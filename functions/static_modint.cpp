#include<bits/stdc++.h>

namespace yxr {
  namespace internal {
    struct modint_base {};
    struct static_modint_base : modint_base {};
  }  // namespace internal
  template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct static_modint : internal::static_modint_base {
      using mint = static_modint;

      public:
      static constexpr int mod() { return m; }
      static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
      }

      static_modint() : _v(0) {}
      static_modint(long long v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
      }

      unsigned int val() const { return _v; }

      mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
      }
      mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
      }
      mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
      }
      mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
      }

      mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
      }
      mint& operator-=(const mint& rhs) {
        _v += umod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
      }
      mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
      }
      mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

      mint operator+() const { return *this; }
      mint operator-() const { return mint() - *this; }

      mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
          if (n & 1) r *= x;
          x *= x;
          n >>= 1;
        }
        return r;
      }
      mint inv() const {
        return pow(umod() - 2);
      }

      friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
      }
      friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
      }
      friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
      }
      friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
      }
      friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
      }
      friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
      }

      private:
      unsigned int _v;
      static constexpr unsigned int umod() { return m; }
    };
  using modint998244353 = static_modint<998244353>;
  using modint1000000007 = static_modint<1000000007>;
}  // namespace yxr

