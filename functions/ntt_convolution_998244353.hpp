#include <bits/stdc++.h>
namespace CMM{
  const int _mod = 998244353;
  class modint{
    private:
      long long _v;
    public:
      modint() :_v(0) {  }
      modint(long long _a) { // dont use modint{value}, use modint(value)
        _v = (_a < 0)? _mod - ((-_a) % _mod) : (_a % _mod);
      }

      int val()const { return _v; }
      modint operator+()const { return *this; }
      modint operator-()const { return { _mod - _v }; }
      modint operator+(const modint& rhs) const { return modint(*this) += rhs; }
      modint operator-(const modint& rhs) const { return modint(*this) -= rhs; }
      modint operator*(const modint& rhs) const { return modint(*this) *= rhs; }
      modint operator/(const modint& rhs) const { return modint(*this) /= rhs; }

      bool operator==(const modint& rhs)const { return _v == rhs._v; }
      bool operator!=(const modint& rhs)const { return _v != rhs._v; }
      bool operator> (const modint& rhs)const { return _v >  rhs._v; }
      bool operator>=(const modint& rhs)const { return _v >= rhs._v; }
      bool operator<=(const modint& rhs)const { return _v <= rhs._v; }
      bool operator< (const modint& rhs)const { return _v <  rhs._v; }

      modint& operator+=(const modint& rhs) {
        (_v += rhs._v) %= _mod;
        return *this;
      }
      modint& operator-=(const modint& rhs) {
        (_v += _mod - rhs._v) %= _mod;
        return *this;
      }
      modint& operator*=(const modint& rhs) {
        _v = _v * rhs.val() % _mod;
        return *this;
      }
      modint& operator/=(const modint& rhs) { // 费马小定理
        _v = _v * rhs.inv().val() % _mod ;
        return *this;
      }
      modint pow(long long pwr) const {
        long long res(1);
        long long _b(_v);
        while (pwr) {
          if (pwr & 1) (res *= _b) %= _mod;
          (_b *= _b) %= _mod;
          pwr /= 2;
        }
        return res;
      }
      modint inv() const {
        assert(_v != 0);
        return pow(_mod - 2);
      }
  };

  template<class T> // mod type T
    class Binomial{
      public:
        std::vector<T> fac;
        std::vector<T> ifac;
        std::vector<T> inv;
        Binomial(){};
        void init(int n) { // [0,n]
          fac.resize(n+1,1);
          ifac.resize(n+1);
          inv.resize(n+1);
          for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
          ifac[n]=fac[n].inv();
          for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1);
          for(int i=1;i<=n;i++) inv[i]=fac[i-1]*ifac[i];
        }
        Binomial(int n){ init(n); }
    };

  namespace NTT{
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

    template<class T>
      T mypow(T a, long long k) { //快速幂，a**k
        T res = 1;
        while (k) {
          if (k & 1) (res *= a); // modint %= MOD;
          (a *= a); // modint %= MOD;
          k >>= 1;
        }
        return res;
      }

    template<class mint>
      void NTT(std::vector<mint> &A, int flag = 1 /* 1: NTT, -1: INTT*/ ) {
        int n = A.size();
        if(n == 1) return ;
        // assert((n & (n-1)) == 0); // 2 的幂次
        int lgn = getlog2(n);
        // assert(lgn <= MAXPWR);
        for(int i=0;i<n;i++) { // 同FFT
          int j = rev(i, lgn);
          if (j > i) std::swap(A[i], A[j]);
        }
        for(int pwr=0;pwr<lgn;pwr++){
          int m = 1 << pwr;
          // assert((MOD - 1) % (m<<1) == 0);
          mint gn = mypow<mint>(flag == 1 ? g : invg, (MOD - 1) / (m << 1)); // 单位原根g_n
          for (int k = 0; k < n; k += (m<<1)) {
            mint gi = 1;
            for(int j=0;j<m;j++){
              mint U = A[k + j];
              mint T = A[k + j + m] * gi;
              A[k + j] = (U + T);
              A[k + j + m] = (U - T);
              gi *= gn;
            }
          }
        }
        if(flag == -1){ // 内置 / N
          const mint INVSIZE = mint(n).inv(); //  mypow(n, MOD-2);
          for(int i=0;i<n;i++) (A[i] *= INVSIZE) ; // modint %= MOD;
        }
      }

    template<class T>
      void INTT(std::vector<T> &A){ NTT<T>(A,-1);}

    // 卷积
    template<class T>
      std::vector<T> convolution(std::vector<T> v0, std::vector<T> v1){
        int sz = v0.size() + v1.size();
        if(sz == 0)return {};
        sz = 1 << (getlog2(sz) + !!(sz & (sz-1))); // 非2的幂次
        v0.resize(sz,0);
        v1.resize(sz,0);
        NTT<T>(v0);
        NTT<T>(v1);
        std::vector<T> v2(sz,0);
        for(int i=0;i<sz;i++) v2[i] = v0[i] * v1[i]; // modint % MOD;
        INTT<T>(v2);
        return v2;
      }

    // 平方 少一次 NTT
    template<class T>
      std::vector<T> poly_sq(std::vector<T> v0) {
        int sz = v0.size() * 2;
        if(sz == 0)return {};
        sz = 1 << (getlog2(sz) + !!(sz & (sz-1))); // 非2的幂次
        v0.resize(sz,0);
        NTT<T>(v0);
        std::vector<T> v2(sz,0);
        for(int i=0;i<sz;i++) v2[i] = v0[i] * v0[i]; // modint % MOD;
        INTT<T>(v2);
        return v2;
      }
  }
};
// ---------- template end ----------
using mint = CMM::modint;

