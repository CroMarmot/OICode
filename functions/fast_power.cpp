ll fast_power(ll base, ll power) {
  assert(power >= 0);
  ll ret = 1;
  while(power) {
    if(power & 1)
      ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}

