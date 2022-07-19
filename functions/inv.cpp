#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)

ll read(){ll r;scanf("%lld",&r);return r;} // read
int n;
int MOD;

struct ModInt{
  int v;
  ModInt(ll val = 0) :v(val) { }
};

ll real(const ModInt & v0){
  return (v0.v + MOD) % MOD;
}

ModInt operator+(const ModInt & v0, const ModInt &v1){
  return (v0.v + v1.v) % MOD;
}

ModInt operator-(const ModInt & v0, const ModInt &v1){
  return (v0.v - v1.v) % MOD;
}

ModInt operator*(const ModInt & v0, const ModInt &v1){
  return ((ll)v0.v * (ll)v1.v) % MOD;
}

ModInt fac[2010] = {1};
ModInt invv[2010] = {1};
ModInt invfac[2010] = {1};
ModInt C(int n,int m) { return fac[n] * invfac[m] * invfac[n-m]; }

int main(){
  n = read();
  MOD = read();

  // 30 ms
  rep(i,1,n+1) fac[i] = fac[i-1] * i;
  invv[1] = 1;
  rep(i,2,n+1) invv[i] = (MOD-MOD/i) * invv[MOD%i];
  rep(i,1,n+1) invfac[i] = invfac[i-1] * invv[i];
}
