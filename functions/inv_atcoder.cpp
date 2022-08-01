#include<bits/stdc++.h>
#include<atcoder/all>
using mint = atcoder::modint998244353;
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)

ll read(){ll r;scanf("%lld",&r);return r;} // read

namespace INVLIB{
  template<class T,int MOD>
  class InvFacBinom{
    vector<T> _inv;
    int _n;
  public:
    vector<T> fac;
    vector<T> invfac;
    InvFacBinom(int n):_n(n){
      fac = vector<T> (n+1,1);
      _inv = vector<T> (n+1,1);
      invfac = vector<T> (n+1,1);
      rep(i,1,n+1) fac[i] = fac[i-1] * i;
      rep(i,2,n+1) _inv[i] = (MOD-MOD/i) * _inv[MOD%i];
      rep(i,1,n+1) invfac[i] = invfac[i-1] * _inv[i];
    }
    T inv(int v){
      assert(v > 0 && v <= _n && v < MOD);
      return _inv[v];
    }
    T binom(int n,int m) { return fac[n] * invfac[m] * invfac[n-m]; }
  };
}


int main(){
  auto ifb = INVLIB::InvFacBinom<mint, 998244353>(50000);
  // 30 ms
  printf("binom(5,3) = %d\n", ifb.binom(5,3).val() );
  printf("inv2 = %d\n",ifb.inv(2).val());
  printf("fac[4] = %d\n",ifb.fac[4].val());
  printf("invfac[5] = %d\n",ifb.invfac[5].val());
  return 0;
}
