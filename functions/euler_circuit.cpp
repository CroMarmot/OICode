#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back

vector<int> euler_circuit(vector<vector<pair<int, int>>> G, int n/*点*/, int m/*边*/) { // 欧拉回路
  vector<int> path;
  vector<bool> used(m, false); // 边是否被使用
  function<void(int)> dfs=[&](int u) {
    for(auto [v,e]: G[u]) { // (点, 边)
      if(!used[e]) {
        used[e] = true;
        dfs(v);
      }
    }
    path.push_back(u);
  };
  dfs(0);
  reverse(path.begin(), path.end());
  return path;
}

int main(){
  return 0;
}


