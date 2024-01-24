/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @file        : mincut
 * @created     : 星期日 6月 26, 2022 04:39:50 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back
const double pi = acos(-1.0);

const int INF = 0x3f3f3f3f;
// 支持重边
class MinCut{
  int sz ;
  // TODO 优化成正反边下标
  vector<unordered_map<int,ll> > G; // {idx,weight}
  vector<int> d; // bfs 距离

public:
  MinCut(int n):sz(n){
    G = vector<unordered_map<int,ll> >(sz);
  }
  // 点范围 [0..n-1]
  void path(int u,int v,ll w){
    assert(u != v);
    G[u][v] += w;
  }

  int dfs(int u,int en, ll s){
    if (u == en)return s;
    for(auto [v,w]:G[u]){
      if(w == 0) continue;
      if(d[v] != d[u]+1) continue;
      int r = dfs(v,en,min(s,w));
      if(r){
        G[u][v] -= r;
        G[v][u] += r;
        return r;
      }
    }
    d[u] = 0; // 标记无效 替代vis
    return 0;
  }

  bool bfs(int st,int en){
    d = vector<int>(sz+10,-1);
    vector<int> q = {st};
    d[st] = 0;
    rep(i,0,q.size()){
      int u = q[i];
      for(auto [v,w]: G[u]){ // u -> v, weight =w
        if(d[v] != -1) continue;
        if(w == 0) continue;
        d[v] = d[u] +1;
        q.pb(v);
      }
    }
    return d[en] >= 0;
  }
  // 一次性计算
  ll calc(int st,int en){
    int ans = 0;
    while (bfs(st, en)) ans += dfs(st, en, INF);
    return ans;
  }
};


int main(){
  MinCut mc(100);
  mc.path(0,1,20);
  mc.path(1,3,10);
  mc.path(1,2,10);
  mc.path(2,4,INF);
  mc.path(3,4,INF);
  printf("%lld\n",mc.calc(0,4));
  return 0;
}

