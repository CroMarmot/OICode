#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define pb push_back

/* construct: vertexsize
 *    auto tarjan = new Tarjan(vertex_size)
 *
 * p2 // 1<=from_vertex,to_vertex<= vertex_size
 *    tarjan.p2(from_vertex,to_vertex)
 *
 * prepare an result array,and calc
 *    int res[vertex_size+1];
 *    tarjan.calc(res);
 *
 * return:
 *    res[vertex_id]  ===== after_tarjan_vertex_group_id
 */
class Tarjan{
  const int STATE_VISITED = 0x1;
  const int STATE_INSTACK = 0x2;
  vector<int> low; // lowest node 该节点在深度搜索中 它自己以及它的子节点 能够触及的 最小的id
  vector<int> dfn; // deep first node 按照先序深度搜索顺序 分配的id
  stack<int> stk; // stack 深搜的stk
  vector<int> vstate; // 节点状态 = {栈中,访问过}
  vector<vector<int> > p; // 单向边
  int n;
  // strongly connected components强联通分量
  void scc(int v) {
    if(vstate[v] & STATE_VISITED) return ;
    static int id = 0;
    low[v] = dfn[v] = ++id; // 初始化当前下标和最小达到下标
    stk.push(v);
    vstate[v] = STATE_VISITED | STATE_INSTACK;
    for(auto w:p[v]){
      // 需要注意的是 可能一个子点因为深搜先在其它分支访问了, dfn更小, 是visited但是不在栈中,这种不要更新
      if(!(vstate[w] & STATE_VISITED)){ // 1->2->4,1->3->4, 省去第二次再搜索4 复杂度节点访问次数限制在节点个数以内
        scc(w);
        low[v] = min(low[v],low[w]);  //v或v的子树能够追溯到的最早的栈中节点的次序编号
      } else if(vstate[w] & STATE_INSTACK){ //v->w后向边
        low[v] = min(low[v],dfn[w]);
      }
    }
    // 非对称出栈, 访问时入栈, 但是 要找到根才会把向下的都出栈
    int u;
    if(low[v] == dfn[v])  { // 递归结束后，如果该节点的最小id=实际id，还在stk上，该节点以下的所有节点形成一个强连通分量
      do{
        u = stk.top();
        stk.pop();
        dfn[u] = v;  //缩点, 因为节点通过visited保证只会访问一次，所以这里也不会再访问dfn，利用这个来记录强连通关系
        vstate[u] &= ~STATE_INSTACK;    //出栈解除标记
      }while(u != v);
    }
  }
public:
  Tarjan(int SZ):n(SZ){
    low = vector<int>(n+1);
    stk = {};
    vector<int>(n+1);
    dfn = vector<int>(n+1);
    vstate = vector<int>(n+1);
    p = vector<vector<int> >(n+1);
  }
  void calc(vector<int> & ret){
    ret = vector<int>(n+1);
    rep(i,1,n+1){
      scc(i);
    }
    rep(i,1,n+1){
      ret[i]=dfn[i];
    }
  }
  void p2(int i,int j){
    p[i].pb(j);
  }
};

int n,m;
vector<int>num; // scc 联通分量 标识
int ans = 0;

int main(){
  // 点,有向边,
  cin>>n>>m;
  Tarjan tarjan(n);
  rep(i,0,m){
    int u,v;
    scanf("%d %d",&u,&v);
    tarjan.p2(u,v);
  }
  tarjan.calc(num);
  rep(i,1,n+1){
    printf("%lld: %d\n",i,num[i]);
  }

  return 0;
}


/*
tarjan(u){
    DFN[u] = Low[u] = ++Index//为节点u设定次序编号和Low初值
    Stack.push(u) //将节点u压入栈中
    for each(u,v) in E //枚举每一条边
        if (v not visited) //如果节点v未被访问过
            tarjan(v) //继续向下找
            Low[u]=min(Low[u],Low[v])
        else if (v in S) //如果节点v还在栈内
                Low[u]=min(Low[u], DFN[v])
    if ( DFN[u] == Low[u] ){ //如果节点u是强连通分量的根
        component = {}
        repeat{
            v = S.pop//将v退栈，为该强连通分量中一个顶点
            component.append(v)
            until( u == v)
        }
        print component
    }
}
 * */

/**
1->2->3->1
3->4->5

5 5
1 2
2 3
3 1
3 4
4 5
 */
