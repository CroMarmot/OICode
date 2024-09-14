#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)

ll read(){ll r;scanf("%lld",&r);return r;}

// TODO 抽象个Persistence 持久化+ lazy segtree , 暂时还不支持抽象范围和动态增点.
// https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
// atcoder的库整个实现了 空间是2n, 然后操作去掉了递归化
// abc348G
// https://atcoder.jp/contests/abc348/submissions/57713468
namespace cmm {
  // 所有区间左闭右开 [l,r)
  template <class S, // S 节点类型
           auto I, // I 是单位元生成函数, up(A,I()) = A, Identity
           auto up, // parent = up(left child,right child), up应该满足结合率
           auto down> // lazy状态的向下扩展 down(&parent,&left,&right)
  struct persistence_lazy_segtree {
    static_assert(std::is_convertible_v<decltype(I), std::function<S()>>, "I must work as S()");
    static_assert(std::is_convertible_v<decltype(up), std::function<S(const S&,const S&)>>, "up must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(down), std::function<void(S&,S&,S&)>>, "down must work as void(S&,S&,S&)");

    public:
    #define mid (l+r)/2
    #define L_CHILD d[o].l,l,mid
    #define R_CHILD d[o].r,mid,r
    #define LR_ROOT 0,_n
    struct TreeStruct{
      S data;
      int l=-1; // 动态vector 还是不要指针的好, index 更好
      int r=-1;
      TreeStruct(){ data = I(); }
    };
    // TODO 这种 函数到底传递l,r更好吗?
    std::vector<TreeStruct> d;
    explicit persistence_lazy_segtree(int n) : _n(n) {}; // 叶子节点个数不能变
    int build(function<void(S&node,int pos)>&&init_leaf_fn) { return build(LR_ROOT,std::move(init_leaf_fn)); }
    int persistence_update(int o,int ql,int qr, function<void(S&o)>&&handle_seg_fn){ return persistence_update(o,LR_ROOT,ql,qr,std::move(handle_seg_fn)); }
    void update(int o,int ql,int qr, function<void(S&)>&&handle_seg_fn){ return update(o,LR_ROOT,ql,qr,std::move(handle_seg_fn)); }
    S query(int o, int ql, int qr) { return query(o,LR_ROOT,ql,qr); }
    // atcoder 有max_right和min_left实现binary search
    // g(一个合并的S) 返回 不满足 或 满足, atcoder库这里返回的是index而不是结果, [因为 有时我们需要分界点左侧有时需要分界点右侧多一个
    // 保证 g(I()) == true ??? 整个二分结构应该是  [true ...true][false... false]
    //                                                            ^
    //                                                            | 返回这个index
    // 返回的结果范围在 [0 ~ n]
    pair<int,S> min_left(int o,function<bool(const S&)>&& g) { assert(g(I())); return min_left(o,LR_ROOT,std::move(g)); }
    void leaf(int o,vector<S>&res) { return leaf(o,LR_ROOT,res); }

    private:
    int new_node() {// vector的引用是不稳定的, 用index而不是地址
      d.push_back(TreeStruct());
      return d.size()-1;
    }
    int build(int l,int r, function<void(S&node,int pos)>&&init_leaf_fn) { // 返回根节点, 保证调用且之调用一次
      int o = new_node();
      if(r-l==1){
        init_leaf_fn(d[o].data,l);
        return o;
      }
      d[o].l=build(l,mid,std::move(init_leaf_fn));
      d[o].r=build(mid,r,std::move(init_leaf_fn));
      d[o].data = up(d[d[o].l].data,d[d[o].r].data);
      return o;
    }
    // 对于持久化update, 返回新的root_id, 会使用=进行深拷贝原来的节点
    int persistence_update(int o,int l,int r,int ql,int qr, function<void(S&o)>&&handle_seg_fn){
      assert(qr > ql);
      int new_o=new_node();
      d[new_o] = d[o]; // 深拷贝
      o=new_o;
      if(ql<=l and r<=qr) {
        handle_seg_fn(d[o].data);
        return o;
      }
      down(d[o].data,d[d[o].l].data,d[d[o].r].data);
      if(ql < mid) d[o].l = persistence_update(L_CHILD,ql,qr,std::move(handle_seg_fn));
      if(qr > mid) d[o].r = persistence_update(R_CHILD,ql,qr,std::move(handle_seg_fn));
      d[o].data = up(d[d[o].l].data,d[d[o].r].data);
      return o;
    }
    // 对于非持久化的update
    void update(int o,int l,int r,int ql,int qr, function<void(S&)>&&handle_seg_fn){
      assert(qr > ql);
      if(ql<=l and r<=qr) return handle_seg_fn(d[o].data);
      down(d[o].data,d[d[o].l].data,d[d[o].r].data);
      if(ql < mid) update(L_CHILD,ql,qr,std::move(handle_seg_fn));
      if(qr > mid) update(R_CHILD,ql,qr,std::move(handle_seg_fn));
      d[o].data = up(d[d[o].l].data,d[d[o].r].data);
    }
    // up( [ql...qr) )
    S query(int o,int l,int r,int ql,int qr) {
      if (ql == qr) return I();
      assert(ql < qr);
      if(ql<=l and r<=qr) { return d[o].data; }
      down(d[o].data,d[d[o].l].data,d[d[o].r].data);
      assert(ql < mid or qr > mid);
      if(qr <= mid) return query(L_CHILD,ql,qr);
      if(ql >= mid) return query(R_CHILD,ql,qr);
      return up(query(L_CHILD,ql,qr),query(R_CHILD,ql,qr));
    }
    pair<int,S> min_left(int o,int l,int r,function<bool(const S&)>&& g) {
      if(g(d[o].data)) return {r,d[o].data};
      S cur = I();
      while(true) {
        if(r-l==1) {
          S use_tot = up(cur,d[o].data);
          if(g(use_tot)) {
            return {r,use_tot};
          }else{
            return {l,cur};
          }
        }
        S use_left = up(cur,d[d[o].l].data);
        if(!g(use_left)) { // d[o].l,l,mid
          r=mid;
          o=d[o].l;
        }else{             // d[o].r,mid,r
          l=mid;
          o=d[o].r;
          cur=use_left;
        }
      }
      assert(false);
      return {-1,I()};
    }
    void leaf(int o,int l,int r,vector<S>&res) {
      if(r-l==1) {
        res[l] = d[o].data;
        return ;
      }
      down(d[o].data,d[d[o].l].data,d[d[o].r].data);
      leaf(L_CHILD,res);
      leaf(R_CHILD,res);
    }
    int _n;
  };
};  // namespace cmm

// ---

struct NODE{
  ll v=0; // leaf是值, 非leaf是lazy
  ll s=0; // 区间和
  int sz=0;
  // int l; // 在node实现中没有直接提供l,r  只有leaf提供, 所以如果对l,r有需要的话 可以自己实现,
  // int r;
};

void add_fn(NODE&o,ll val){ // 整个区间加, 这在atcoder里是 mapping和
  o.v+=val;
  o.s+=val*o.sz;
};


int main(){
  // 参考 abc348G
  // 实现 区间求和 和 区间增加 demo

  int n=5;
  auto node_identity= [&](){return NODE();};
  auto init_leaf_fn = [&](NODE&node,int pos){
    node.s = node.v = pos;
    node.sz = 1;
  };
  auto down_fn = [&](NODE&o,NODE&l,NODE&r){
    if(o.v!=0) {
      add_fn(l, o.v);
      add_fn(r, o.v);
      o.v=0;
    }
  }; // lazy down
  auto up_fn = [](const NODE&l,const NODE&r){
    NODE o=NODE();
    o.s = l.s+r.s;
    o.sz = l.sz + r.sz;
    return o;
  };
  auto tree=cmm::persistence_lazy_segtree<
    NODE,
    node_identity,
    up_fn,
    down_fn
  >(n);
  // 必须 创建初始节点
  int root_id = tree.build(init_leaf_fn);
  tree.update(root_id,0,1,[](NODE&node){ node.s=node.v=100; }); // a[0]=100
  printf("%lld\n", tree.query(root_id,0,3).s ); // sum a[0]+a[1]+a[2]
  int new_root = tree.persistence_update(root_id,1,3,[&](NODE&node){ add_fn(node,3); }); // a[1..2] +=3
  printf("%lld\n", tree.query(new_root,0,3).s ); // sum 新的数组中 a[0]+a[1]+a[2]
  printf("%lld\n", tree.query(root_id,0,3).s ); // sum 老的数组中 a[0]+a[1]+a[2]
  return 0;
}

