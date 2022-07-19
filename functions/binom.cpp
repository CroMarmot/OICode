/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @file        : binom
 * @created     : 星期二 7月 19, 2022 21:40:16 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back
const double pi = acos(-1.0);

ll read(){ll r;scanf("%lld",&r);return r;} // read


int main(){
  int n = read();
  int P = read();
  std::vector binom(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % P;
    }
  }

  return 0;
}

