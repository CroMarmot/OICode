#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
#define rep(i,a,n) for (ll i=a;i<n;i++)

// TODO overflow
ll quick_p(ll b, ll p,ll mod){
  __int128_t r = 1;
  while(p){
    if(p%2)(r*=b)%=mod;
    (b*=b)%=mod;
    assert(r>0);
    assert(b>0);
    p/=2;
  }
  return r%mod;
}

bool is_prime_64(ll v){
  if(v == 2)return true;
  if(v < 2)return false;
  if(v%2 == 0)return false;
  ll test_g[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  ll startp = v-1;
  while(startp%2 == 0)startp>>=1;
  rep(i,0,7){
    ll p = startp;
    ll base = test_g[i];
    // don't break may cause 4033 bug
    if(base % v == 0)continue;
    bool find = false;
    ll r = quick_p(base,p,v);
    while(p != v-1){
      if(r == v-1){
        find = true;
        break;
      }
      // -1 开始的序列, 或全1序列
      if(r == 1){
        if(p == startp){
          find = true;
          break;
        }
        return false;
      }
      p*=2;
      (r*=r)%=v;
    }
    if(!find){
      return false;
    }
  }
  return true;
}

int main(){
  vector<ll> arr = {3,5,11,15,17,19,30,325,1234,2047,4033/*37*109 */,998244353,1000000007,1000000009};
  for(auto item:arr){
    printf("%lld:%d\n",item,is_prime_64(item));
  }
  return 0;
}

