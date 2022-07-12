#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
typedef long long ll;
const int MAX = 2e5+10;
struct AC_Automaton {
  static const int K=26;//may need change
  static const int MAX_NODE=2e5+10;
  int getid(char c) {//may need change
    return c-'a';
  }
  struct AC_NODE{
    AC_NODE * next[K]; // 能匹配 节点跳转
    AC_NODE * fail; // 不能匹配的 后续节点
    AC_NODE * last; // suffix 后缀跳转
    int cnt; // 到该节点计数
    int dep; // 深度
    void init(AC_NODE * ac_n,int d){
      // 默认指向根节点
      rep(i,0,K){
        next[i] = ac_n;
      }
      fail = ac_n;
      last = ac_n;
      cnt = 0;
      dep = d;
    }
  }nodes[MAX_NODE];
  AC_NODE * root = nodes;
  int tot;
  AC_NODE * newnode(int dep) {
    nodes[tot].init(root,dep);
    return &nodes[tot++];
  }
  void init() {
    tot=0;
    root=newnode(0);
  }
  void insert(char *s) {
    AC_NODE * now = root;
    int len=strlen(s);
    rep(i,0,len){
      int t=getid(s[i]);
      if(now->next[t] == root) {
        now->next[t] = newnode(i+1);
      }
      now=now->next[t];
    }
    now->cnt++;
  }
  void setfail() {
    queue<AC_NODE *>q;
    rep(i,0,K){
      if(root->next[i] != root){
        q.push(root->next[i]);
      }
    }
    while(!q.empty()){
      AC_NODE * now=q.front();
      q.pop();
      //suffix link 预处理掉 fail 的后缀跳转
      now->last = now->fail->cnt > 0 ? now->fail : now->fail->last;
      rep(i,0,K){
        if(now->next[i] != root) { // 基本的fail链接
          now->next[i]->fail=now->fail->next[i];
          q.push(now->next[i]);
        }else{
          now->next[i]=now->fail->next[i]; // 预处理掉 减少 work时再 逐级下降
        }
      }
    }
  }
  void dump(AC_NODE * ac_n = NULL,int offset = 0,char ch = '?'){
    if(!ac_n){
      ac_n = root;
    }
    rep(i,0,offset){
      printf("\t");
    }
    printf("%c\t",ch);
    printf("%p last:%p fail:%p\n",ac_n,ac_n->last,ac_n->fail);
    rep(i,0,K){
      if(ac_n -> next[i] -> dep > ac_n -> dep){
        dump(ac_n -> next[i],offset + 1,i+'a');
      }
    }
  }
  void work(char *s,ll *be,ll *en) {
    int n = strlen(s);
    AC_NODE * now = root;
    rep(i,0,n+1){ // 最后一个字符 '\0'一定不会匹配
      be[i]=en[i]=0;
    }
    rep(i,0,n){
      now=now->next[getid(s[i])];
      AC_NODE * tmp = root;
      if(now->cnt){ // 本身是后缀
        tmp=now;
      }else if(now->last->cnt){ // 是某个存在的字串后缀
        tmp=now->last;
      }
      while(tmp != root){ // 累和
        en[i]+=tmp->cnt;
        // assert(i-tmp->dep+1 >= 0);
        be[i-tmp->dep+1]+=tmp->cnt;
        tmp=tmp->last;
      }
    }
  }
}ac;
char s[MAX],tmp[MAX];
ll be[MAX],en[MAX];
int main() {
  int q;
  scanf("%s",s);
  ac.init();
  scanf("%d",&q);
  while(q--) {
    scanf("%s",tmp);
    ac.insert(tmp);
  }
  ac.setfail();
  ac.dump();
  // 变成 前缀
  ac.work(s,be,en);
  ll ans=0;
  int n = strlen(s);
  rep(i,0,n-1){
    ans+=en[i]*be[i+1];
  }
  printf("%lld\n",ans);
  return 0;
}
