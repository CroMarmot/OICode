#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)

namespace NTT998{
  const int MOD = 998244353; // 7*17*2^23 + 1
  const int MAXPWR = 22; // 随着MOD改变, 2的幂次, 对应复平面单位向量的N = 2 && MAXPWR;
  const int g = 3;// 原根 随着MOD改变
  const int invg = 332748118;// 原根模逆元 随着MOD 和 g 改变

  // bit 翻转
  int rev(int x, int len) {
    int ans = 0;
    while(len -- ){
      ans <<= 1;
      ans |= x & 1;
      x >>= 1;
    }
    return ans;
  }

  inline int getlog2(int n){ return 31 - __builtin_clz(n);}

  ll mypow(ll a, ll k) { //快速幂，a**k
    ll res = 1;
    while (k) {
      if (k & 1) (res *= a) %= MOD;
      (a *= a) %= MOD;
      k >>= 1;
    }
    return res;
  }

  void NTT(vector<ll> &A, int flag = 1 /* 1: NTT, -1: INTT*/ ) {
    int n = A.size();
    if(n == 1) return ;
    // assert((n & (n-1)) == 0); // 2 的幂次
    int lgn = getlog2(n);
    // assert(lgn <= MAXPWR);
    rep(i, 0, n) { // 同FFT
      int j = rev(i, lgn);
      if (j > i) swap(A[i], A[j]);
    }
    rep(pwr,0,lgn){
      int m = 1 << pwr;
      // assert((MOD - 1) % (m<<1) == 0);
      ll gn = mypow(flag == 1 ? g : invg, (MOD - 1) / (m << 1)); // 单位原根g_n
      for (int k = 0; k < n; k += (m<<1)) {
        ll gi = 1;
        rep(j,0,m) {
          auto U = A[k + j];
          auto T = gi * A[k + j + m] % MOD;
          A[k + j] = (U + T) % MOD;
          A[k + j + m] = (U - T + MOD) % MOD;
          (gi *= gn) %= MOD;
        }
      }
    }
    if(flag == -1){ // 内置 / N
      const ll INVSIZE = mypow(n, MOD-2);
      rep(i,0,n) (A[i] *= INVSIZE) %= MOD;
    }
  }

  void INTT(vector<ll> &A){ NTT(A,-1);}

  // 卷积
  // 注意会修改传入数组(引用不要引用同一个内容), 如不希望修改 在外部备份, 原始传入尽量不要带后缀零
  vector<ll> convolution(vector<ll> &v0, vector<ll> &v1){
    int sz = v0.size() + v1.size();
    if(sz == 0)return {};
    sz = 1 << (getlog2(sz) + !!(sz & (sz-1))); // 非2的幂次
    v0.resize(sz,0);
    v1.resize(sz,0);
    NTT(v0);
    NTT(v1);
    vector<ll> v2(sz,0);
    rep(i,0,sz) v2[i] = v0[i] * v1[i] % MOD;
    INTT(v2);
    return v2;
  }

  // 平方 少一次 NTT 注意会修改传入数组, 如不希望修改 在外部备份
  vector<ll> poly_sq(vector<ll> &v0) {
    int sz = v0.size() * 2;
    if(sz == 0)return {};
    sz = 1 << (getlog2(sz) + !!(sz & (sz-1))); // 非2的幂次
    v0.resize(sz,0);
    NTT(v0);
    vector<ll> v2(sz,0);
    rep(i,0,sz) v2[i] = v0[i] * v0[i] % MOD;
    INTT(v2);
    return v2;
  }
}

int main(){
  // 123*456 = 56088
  const int SIZE = 8; // 一定要是2的幂次
  auto a = vector<ll>{3,2,1};
  auto b = vector<ll>{6,5,4};
  // 计算
  auto c = NTT998::convolution(a,b);
  // 输出
  rep(i,0,SIZE) printf("(%lld)", c[i]);
  printf("\n");
  rep(i,0,SIZE-1) {// 进位
    c[i+1] += c[i] / 10;
    c[i] -= (c[i] / 10) * 10;
  }
  rep(i,0,SIZE) printf("(%lld)", c[i]);
  printf("\n");
  return 0;
}

