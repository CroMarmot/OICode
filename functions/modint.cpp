#include <bits/stdc++.h>
namespace CMM{
  const int _mod = 998244353;
  class modint{
    private:
      long long _v;
    public:
      modint() :_v(0) {  }
      modint(long long _a) {
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
};
