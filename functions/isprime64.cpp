#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)

// Care overflow
typedef __int128_t lll;
ll quick_p(lll b, ll p,ll mod){
  lll r = 1;
  while(p){
    if(p%2)(r*=b)%=mod;
    (b*=b)%=mod;
    p/=2;
  }
  return r%mod;
}

bool miller_robin(ll v, ll base, ll startpwr){
  lll r = quick_p(base,startpwr,v);
  for(ll p = startpwr; p < v-1; p *=2){
    if(r == v-1) return true; // -1 开始的序列
    if(r == 1) return p == startpwr; // 全1序列
    (r*=r)%=v;
  }
  return false;
}

bool is_prime_64(ll v){
  if(v == 2)return true;
  if(v < 2 || v % 2 == 0)return false;
  ll p = v-1;
  while(p % 2 == 0) p /= 2;
  for(auto base:{2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
    if(base % v == 0) continue; // don't break may cause 4033 bug
    // 需要所有都能找到-1开始, 或奇数次开始 全1
    if(!miller_robin(v,base,p)) return false;
  }
  return true;
}

int main(){
  vector<ll> arr = {3,5,11,15,17,19,30,325,1234,2047,4033/*37*109 */,998244353,1000000007,1000000009};
  vector<bool> res = {1,1,1,0,1,1,0,0,0,0,0,1,1,1};
  rep(i,0,arr.size()){
    auto item = arr[i];
    bool r = is_prime_64(item);
    printf("%lld:\t%d \t%s\n",item, r, r == res[i] ? "OK" :"Failed");
  }
  return 0;
}

