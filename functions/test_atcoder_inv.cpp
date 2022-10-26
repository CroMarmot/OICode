#include<bits/stdc++.h>
#include<atcoder/modint>
#include "./atcoder_inv.cpp"

int main(){
  using mint = atcoder::modint998244353;
  auto ifb = CMM::InvFacBinom<mint, 998244353>(50000);
  // 30 ms
  assert(ifb.binom(5,3).val()==10);
  assert(ifb.inv(2).val()==499122177);
  assert(ifb.fac[4].val()==24);
  assert(ifb.ifac[5].val()==856826403);
  printf("ok\n");
  return 0;
}
