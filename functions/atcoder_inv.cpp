#include<bits/stdc++.h>
namespace CMM{
  template<class T,int MOD> // T should be modint
  class InvFacBinom{
    std::vector<T> _inv;
    int _n;
  public:
    std::vector<T> fac;
    std::vector<T> ifac; // invfac
    InvFacBinom(int n):_n(n){
      fac = std::vector<T> (n+1,1);
      _inv = std::vector<T> (n+1,1);
      ifac = std::vector<T> (n+1,1);
      for(int i=1;i<=n;i++) fac[i] = fac[i-1] * i;
      for(int i=2;i<=n;i++) _inv[i] = (MOD-MOD/i) * _inv[MOD%i];
      for(int i=1;i<=n;i++) ifac[i] = ifac[i-1] * _inv[i];
    }
    T inv(int v)const{
      assert(v > 0 && v <= _n && v < MOD);
      return _inv[v];
    }
    T binom(int n,int m)const{ return (m>n||m<0)?0:fac[n] * ifac[m] * ifac[n-m]; }
  };
}
