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
  vector<vector<int> > sccgroup(){
    rep(i,0,2*n) if(res[i]==-1) scc(i);
    vector<pair<int,int> > gi;
    rep(i,0,2*n) gi.push_back({res[i],i});
    sort(gi.begin(),gi.end());
    vector<vector<int> > group;
    rep(i,0,2*n){
      if(i==0||gi[i].first != gi[i-1].first) group.push_back({gi[i].second}); // new group
      else group.back().push_back(gi[i].second); // same group
    }
    return group;
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
    auto group=sccgroup();
    vector<int> i2g(2*n);
    rep(i,0,group.size()) for(auto idx:group[i]) i2g[idx]=i;
    rep(i,0,n) if(i2g[i*2]==i2g[i*2+1])return false; // 同一个块的真假都在一个scc里
    vector<int> sccmutex(group.size()); // 互斥scc
    rep(i,0,n) { // 每个点的true/false 状态互斥,唯一, 因为建立边时的对称逻辑边
      sccmutex[i2g[i*2]] = i2g[i*2+1];
      sccmutex[i2g[i*2+1]] = i2g[i*2];
    }
    vector<vector<int> > G(group.size()); // 图
    vector<int> degree(group.size(),0);
    // 跨scc的反向边, 做拓扑选择, (因为scc计算后,剩下的一定是偏序不会有环)
    rep(i,0,2*n) for(auto j:p[i]) if(i2g[i]!=i2g[j]) G[i2g[j]].push_back(i2g[i]); // i -> j 反向边
    for(auto &s:G){// 去重
      sort(begin(s),end(s));
      s.resize(unique(begin(s),end(s))-begin(s));
    }
    for(auto &s:G) for(auto t:s) degree[t]++;
    vector<int> d0; // 入度为0
    rep(v,0,degree.size()) if(!degree[v]) d0.push_back(v);
    vector<int> sccpick(group.size(), -1); // scc -1未选, true选/false不选
    rep(i,0,d0.size()) {
      if(sccpick[d0[i]] == -1){ // 没有计算过
        // prinpick("pick %d, unpick %d\n",d0[i],sccmutex[d0[i]]);
        sccpick[d0[i]] = true;
        sccpick[sccmutex[d0[i]]] = false;
      }
      for(auto item:G[d0[i]]) if(!(--degree[item])) d0.push_back(item); // 更新入度排序
    }
    ans = vector<bool>(n);
    rep(i,0,n) ans[i] = sccpick[i2g[i*2+1]];
    return true;
  }
  void then(pair<int,bool> pi, pair<int,bool> pj){ // {i,true/false} -> {j,true/false}
    auto [i,bi] = pi;
    auto [j,bj] = pj;
    assert(i >= 0 && i < n);
    assert(j >= 0 && j < n);
    p[2*i+bi].push_back(2*j+bj);
    if(2*i+bi!=2*j+(!bj)) p[2*j+(!bj)].push_back(2*i+(!bi)); // 自动建立逻辑边
  }
};

int main(){
  int n = 3;
  TwoSat ts(n); // 3 个点
  ts.then({0,false},{1,false});
  ts.then({1,false},{0,false});
  ts.then({1,true},{2,true});
  ts.then({2,true},{1,true});
  ts.then({2,true},{1,false});
  // ts.then({1,false}, {2,true});
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
