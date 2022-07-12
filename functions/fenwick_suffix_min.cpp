#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back
ll read(){ll r;scanf("%lld",&r);return r;} // read

const ll INF = 0x3f3f3f3f3f3f;
struct fenwick_tree {
  vector<ll> bit;
  int n;
  // [0..n-1]
  fenwick_tree(int n) : n(n) {
    bit = vector<ll> (n + 1, INF); // 后缀min fenwick
  }
  // u \in [0..n-1]
  void update(int u, ll v) {
    for (u++; u > 0; u -= u & -u) bit[u] = min(bit[u], v);
  }
  // u \in [0..n-1]
  // return min([u..n-1])
  int query(int u) {
    ll r = INF;
    for (u++; u <= n; u += u & -u) r = min(r, bit[u]);
    return r;
  }
};

int main() {
  fenwick_tree fen(100);
  fen.update(0, 100);
  fen.query(0);
}
