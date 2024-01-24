#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
// #define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
class MaxFlow{
  vector<vector<tuple<int,int>> > G; // {vertex idx,edge idx}
  vector<ll> edge; // 边剩余容量, 偶数正向边, 偶数+1 的逆向边
  vector<int> d; // bfs 距离
public:
  ll INF=0x3f3f3f3f3f3f3f3f;
  // 点范围: [0,n)
  MaxFlow(int n/*点数*/){ G.resize(n); }
  void path(int u,int v,ll cap){ // u->v, 容量
    assert(u != v); // 禁止自环
    assert(0 <= u and u < (int)G.size());
    assert(0 <= v and v < (int)G.size());
    G[u].push_back({v,(int)edge.size()}); edge.push_back(cap); // 正向边
    G[v].push_back({u,(int)edge.size()}); edge.push_back(0); // 反向边
  }
  int dfs(int u,int en, ll flow, vector<tuple<int,int,int,ll> >&flows/*实际流u,v,eid,f*/){
    if (u == en) return flow;
    for(auto [v,eid]:G[u]) if(edge[eid] != 0 and d[v] == d[u]+1) { // 按照bfs距离走
      int r = dfs(v,en,min(flow,edge[eid]),flows); // 实际流量
      if(r) {
        flows.push_back({u,v,eid,r});
        edge[eid  ]-=r;
        edge[eid^1]+=r;
        return r;
      }
    }
    d[u] = 0; // 标记无效 替代vis
    return 0;
  }
  bool bfs(int st,int en){ // 计算bfs距离
    d = vector<int>(G.size(),-1);
    vector<int> q = {st};
    d[st] = 0;
    rep(i,0,q.size()){
      int u = q[i];
      for(auto [v,eid]: G[u]) if(d[v] == -1 and edge[eid] != 0){ // u -> v 有正容量路径
        d[v] = d[u] +1;
        q.push_back(v);
      }
    }
    return d[en] >= 0; // en可达
  }
  // return maxflow, array<tuple<from,to,eid,flow>>
  pair<ll,vector<tuple<int,int,int,ll> > > calc(int st,int en){ // 一次性计算 st -> en
    int ans = 0;
     vector<tuple<int,int,int,ll> > flows;
    while(bfs(st, en)) ans += dfs(st, en, INF,flows);
    return {ans,flows};
  }
  void update_edge(int eid,ll cap){
    edge[eid] = cap;
  }
};

int main(){
  return 0;
}


