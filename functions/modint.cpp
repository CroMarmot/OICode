#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back

namespace MODINT{
  const int _mod = 998244353;
  class modint{
    private:
      ll _v;
    public:
      modint() :_v(0) {  }
      modint(ll _a) {
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
      modint pow(ll pwr) const {
        ll res(1);
        ll _b(_v);
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
};

// int main(){
//   MODINT::modint a = 100000;
//   MODINT::modint b = 100000;
//   printf("%d\n", (a * b).val());
//   return 0;
// }
