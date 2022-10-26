#include<bits/stdc++.h>
namespace CMM{ // inv fac ifac
  template<class T>
  std::vector<T>get_inv(int n, int MOD){ // return [0..n]
    std::vector<T> inv(n+1,0);
    inv[1]=1;
    for(int i=2;i<=n;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i);
    return inv;
  }
  template<class T>
  std::pair<std::vector<T>,std::vector<T>> get_fac_ifac(int n){ // return [0..n]
    std::vector<T> fac(n+1,1);
    std::vector<T> ifac(n+1,1);
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i;
    ifac[n]=fac[n].inv();
    for(int i=n;i-->0;)ifac[i]=ifac[i+1]*(i+1);
    return {fac,ifac};
  }
}
