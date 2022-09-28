#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)

const int maxn = 100000000;
int prime[maxn], tot, mu[maxn];
bool check[maxn];
void CalMu(){
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
  rep(i,1,20) printf("mu[%d] = %d\n",i,mu[i]);
  return 0;
}
