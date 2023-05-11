#include <bits/stdc++.h>
namespace Fenwick{
  // template<class T, T initV,const T& (*fn)(const T&,const T&)>
  template<class T, T initV,T (*fn)(const T&,const T&)>
    struct FenwickBase {
    public:
      const int n;
      std::vector<T> a;
      FenwickBase(int n) : n(n), a(n, initV) {}
      void update(int x, T v) { // [x] -> fn([x], v)
        assert(0<=x and x<n);
        for (int i = x + 1; i <= n; i += i & -i) a[i - 1] = fn(a[i - 1], v);
      }
      T get (int x) { // [0,x)
        assert(0<=x and x<=n);
        T ans = initV;
        for (int i = x; i > 0; i -= i & -i) ans = fn(ans, a[i - 1]);
        return ans;
      }
    };
  template<class T> T max(const T&a,const T&b) {return std::max(a,b);}
  template<class T> T min(const T&a,const T&b) {return std::min(a,b);}
  template<class T> T add(const T&a,const T&b) {return a+b;}

  template<class T, T INF> using FenwickMax = FenwickBase<T, -INF, max<T> >;
  template<class T, T INF> using FenwickMin = FenwickBase<T, INF, min<T> >;
  // template<class T> using FenwickSum = FenwickBase<T, T(0), std::plus<const T&>() >;
  template<class T> using FenwickSum = FenwickBase<T, T(0), add<T> >;

  template<class T>
    struct FenwickRange{ // a[i] = sum_{i=0..x} b_i , s[x] = sum_{i=0..x} b_i (x+1-i)
      int n;
      FenwickBase<T,T(0),add<T> > *b0;
      FenwickBase<T,T(0),add<T> > *b1;
      FenwickRange(int n):n(n){
        b0 = new FenwickBase<T,T(0),add<T> > (n); // sum b_i
        b1 = new FenwickBase<T,T(0),add<T> > (n); // sum b_i(1-i)
      }
      void Add(int l,int r,T v){ // a[l..r] +=v
        assert(0<=l and l<=r and r<this->n);
        b0->update(l, v);
        b1->update(l, v*(1-l));
        if(r+1 < n) {
          b0->update(r+1, -v);
          b1->update(r+1, -v*(1-(r+1)));
        }
      }
      T Query (int l,int r) { // sum(a[l..r] )
        assert(0<=l and l<=r and r<this->n);
        return _preQuery(r+1)-_preQuery(l); // [0..r+1) - [0..l)
      }
    private:
      // sum(a[0..l) ) , x*(sum b_i) + sum(b_i(1-i))
      T _preQuery (int l) { return (l-1)*b0->get(l) + b1->get(l); }
    };
};

int main(){
  const int inf=0x3f3f3f3f;
  { // FenwickMax
    Fenwick::FenwickMax<int, inf> fwmax(100); // [0,100)
    fwmax.update(3,233); // [3] = 233
    fwmax.update(3,122); // [3] = max([3],122) # 失效, 每次只能变更大
    assert(fwmax.get(3) == -inf); // [0,3)
    assert(fwmax.get(4) == 233); // [0,4)
    printf("Max ok\n");
  }

  { // FenwickMin
    Fenwick::FenwickMin<int, inf> fwmin(100); // [0,100)
    fwmin.update(3,233); // [3] = 233
    fwmin.update(3,122); // [3] = min([3],122)
    assert(fwmin.get(3) == inf); // [0,3)
    assert(fwmin.get(4) == 122); // [0,4)
    printf("Min ok\n");
  }

  { // FenwickSum (单点增量, 区间求和)
    Fenwick::FenwickSum<int> fwsum(100); // [0,100)
    fwsum.update(1,99); // [1] += 99
    fwsum.update(2,5); // [2] += 5
    assert(fwsum.get(3) == 104); // [0,3)
    assert(fwsum.get(2) == 99); // [0,4)
    printf("Sum ok\n");
  }

  { // FenwickRange
    Fenwick::FenwickRange<int> fwsum(100); // [0,100)
    fwsum.Add(2,5,3); // [2..5] += 3
    fwsum.Add(1,4,4); // [1..4] += 4
    assert(fwsum.Query(0,1) == 4); // sum [0,1] == 4
    assert(fwsum.Query(2,2) == 7); // sum [2,2] == 7
    assert(fwsum.Query(2,3) == 14); // sum [2,3] == 14
    assert(fwsum.Query(0,5) == 28); // sum [0,5] == 28
    printf("Range Sum and Query ok\n");
  }
  return 0;
}

