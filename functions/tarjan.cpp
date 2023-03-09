#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define pb push_back

class Tarjan{
  vector<int> low;
  vector<int> dfn;
  stack<int> stk;
  vector<int> res;
  vector<vector<int> > p;
  int n;
  void scc(int v) {
    static int id = 0;
    low[v] = dfn[v] = ++id;
    stk.push(v);
    for(auto w:p[v]){
      if(!dfn[w]){ // 未访问过
        scc(w);
        low[v] = min(low[v],low[w]);
      } else if(!res[w]){ // 访问过但没有结果(在栈中)
        low[v] = min(low[v],dfn[w]);
      }
    }
    int u;
    if(low[v] == dfn[v])  {
      do{
        res[u = stk.top()] = v;
        stk.pop();
      }while(u != v);
    }
  }
public:
  Tarjan(int SZ):n(SZ){ // 1-index, [1..SZ]
    low = vector<int>(n+1);
    dfn = vector<int>(n+1);
    stk = {};
    res = vector<int> (n+1);
    p = vector<vector<int> >(n+1);
  }
  vector<int> calc(){
    rep(i,1,n+1){
      if(!res[i]){
        scc(i);
      }
    }
    return res;
  }
  void p2(int i,int j){
    p[i].pb(j);
  }
};

int main(){
  int n,m;
  // 点,有向边,
  cin>>n>>m;
  Tarjan tarjan(n);
  rep(i,0,m){
    int u,v;
    scanf("%d %d",&u,&v);
    tarjan.p2(u,v);
  }
  vector<int> num = tarjan.calc(); // scc 联通分量 标识
  rep(i,1,n+1){
    printf("%lld: %d\n",i,num[i]);
  }
  return 0;
}

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
