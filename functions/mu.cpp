#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

const int maxn = 100000000;
int prime[maxn], tot, mu[maxn];
bool check[maxn];
void calmu(){
  mu[1] = 1;
  rep(i,2,maxn){
    if (!check[i]){
      prime[tot++] = i;
      mu[i] = -1;
    }
    rep(j,0,tot){
      if (i * prime[j] >= maxn) break;
      check[i * prime[j]] = true;
      if (i % prime[j] == 0){
        mu[i * prime[j]] = 0;
        break;
      }else
        mu[i * prime[j]] = -mu[i];
    }
  }
}
int main(){
  CalMu();
  return 0;
}
