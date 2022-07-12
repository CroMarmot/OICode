#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
#define pb push_back

class TwoSat{
  vector<int> low; // 能达到的最小的点
  vector<int> dfn; // tarjan 用的深搜访问次序标识
  stack<int> stk; // tarjan 用的stk
  vector<int> res; // tarjan 结果
  vector<vector<int> > p; // 所有点
  int n;
  void scc(int v) {
    static int id = 0;
    low[v] = dfn[v] = id++;
    stk.push(v);
    for(auto w:p[v]){
      if(dfn[w] == -1){ // 未访问过
        scc(w);
        low[v] = min(low[v],low[w]);
      } else if(res[w] == -1){ // 访问过但没有结果(在栈中)
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
  TwoSat(int SZ):n(SZ){ // 点范围[0..SZ-1]
    low = vector<int>(2*n,-1);
    dfn = vector<int>(2*n,-1);
    stk = {};
    res = vector<int> (2*n,-1);
    p = vector<vector<int> >(2*n);
  }

  bool calc(vector<bool> & ans){
    rep(i,0,2*n) if(res[i] == -1) scc(i);
    // rep(i,0,2*n) printf("scc[%lld] = %d\n",i,res[i]);
    rep(i,0,n) if(res[i*2] == res[i*2+1]) return false; // 同一个块的真假都在一个scc里
    vector<int> revscc(2*n); // 互斥scc
    rep(i,0,n) {
      revscc[res[i*2]] = res[i*2+1];
      revscc[res[i*2+1]] = res[i*2];
    }
    vector<set<int> > scc2scc(2*n);
    unordered_map<int,int> degree; // scc入度
    unordered_map<int,bool> scctf; // scc 真假
    rep(i,0,2*n) { // 跨scc的反向边, 做拓扑选择
      degree[res[i]] = 0;
      for(auto j:p[i]){ // i -> j
        if(res[i] == res[j]) continue;
        scc2scc[res[j]].insert(res[i]);
      }
    }
    for(auto s:scc2scc){
      for(auto t:s) degree[t]++;
    }
    vector<int> d0; // 入度为0
    for(auto [v,d]: degree) if(!d) d0.pb(v);
    rep(i,0,d0.size()) {
      if(!scctf.count(d0[i])){ // 没有选择过
        // printf("pick %d, unpick %d\n",d0[i],revscc[d0[i]]);
        scctf[d0[i]] = true;
        scctf[revscc[d0[i]]] = false;
      }
      for(auto item:scc2scc[d0[i]]) { // 更新入度排序
        if(!(--degree[item])) d0.pb(item);
      }
    }
    ans = vector<bool>(n);
    rep(i,0,n) ans[i] = scctf[res[i*2+1]];
    return true;
  }
  void p2(pair<int,bool> pi, pair<int,bool> pj){ // {i,true/false} -> {j,true/false}
    auto [i,bi] = pi;
    auto [j,bj] = pj;
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);
    p[2*i+bi].pb(2*j+bj);
    p[2*j+(!bj)].pb(2*i+(!bi)); // 自动建立逻辑边
  }
};

int main(){
  int n = 3;
  TwoSat ts(n); // 3 个点
  ts.p2({0,false},{1,false});
  ts.p2({1,false},{0,false});
  ts.p2({1,true},{2,true});
  ts.p2({2,true},{1,true});
  ts.p2({2,true},{1,false});
  // ts.p2({1,false}, {2,true});
  vector<bool> ans = {};
  bool ok = ts.calc(ans); // scc 联通分量 标识
  if(!ok){
    printf("No Answer\n");
    return 0;
  }
  rep(i,0,ans.size()){
    printf("%lld: %d\n",i,(int)ans[i]);
  }
  return 0;
}
