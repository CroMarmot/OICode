#include <bits/stdc++.h>
// #include<atcoder/modint>
#include "./modint.cpp"
#include "./inv.cpp"

int main(){
  int n = 20;
  int MOD = 998244353;
  using mint=CMM::modint;
  auto inv = CMM::get_inv<mint>(n, MOD);
  auto [fac,ifac] = CMM::get_fac_ifac<mint>(n);
  assert(inv[2].val()==499122177);
  assert(fac[4].val()==24);
  assert(ifac[5].val()==856826403);
  printf("ok\n");
  return 0;
}
