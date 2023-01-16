#include <bits/stdc++.h>
typedef long long ll;
#define MOD 998244353
#define rep(i,a,n) for (ll i=a;i<n;i++)
ll read(){ll r;scanf("%lld",&r);return r;} // read

const int N=2000;
int stir2[N+10][N+10]={{1}}; // stirling 2, stir2[n][m] = n个不同球 放m个相同箱子,且每个箱子至少放一个的方案数

int main(){
  rep(i,1,N+1) rep(j,1,i+1) stir2[i][j]=(stir2[i-1][j-1]+stir2[i-1][j]*j%MOD)%MOD;
  return 0;
}

