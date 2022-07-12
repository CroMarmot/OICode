/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @file        : fenwick
 * @created     : 星期三 4月 20, 2022 14:19:18 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->=a;)
#define pb push_back
const double pi = acos(-1.0);

int inf = 0x3f3f3f3f;
struct Fenwick {
  const int n;
  vector<int> a;
  Fenwick(int n) : n(n), a(n, -inf) {}
  // 支持 [0..n) 更新最大值
  void setMax(int x, int v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] = max(a[i - 1], v);
    }
  }
  // 获得 [0,x) 最大值
  int get(int x) {
    int ans = -inf;
    for (int i = x; i > 0; i -= i & -i) {
      ans = max(ans, a[i - 1]);
    }
    return ans;
  }
};

int main(){
  Fenwick fx(100);
  fx.setMax(3,233);
  printf("3:%d\n",fx.get(3));
  printf("4:%d\n",fx.get(4));
  return 0;
}

