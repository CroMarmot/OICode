#include <bits/stdc++.h>
#include <atcoder/convolution>
#include "./atcoder_inv.cpp"

namespace CMM{
  template<class T>
    class Poly{
      std::vector<T>_d;
    public:
      Poly(const std::vector<T> &d):_d(d){};
      friend Poly operator+(const Poly&p0,const Poly&p1){
        std::vector<T>r=p0._d;
        if(p1._d.size()>r.size())r.resize(p1._d.size());
        for(int i=0;i<(int)p1._d.size();i++)r[i]+=p1._d[i];
        return r;
      }
      friend Poly operator-(const Poly&p0,const Poly&p1){
        std::vector<T>r=p0._d;
        if(p1._d.size()>r.size())r.resize(p1._d.size());
        for(int i=0;i<(int)p1._d.size();i++)r[i]-=p1._d[i];
        return r;
      }
      friend Poly operator*(const Poly&p0,const Poly&p1){ // ntt
        return atcoder::convolution(p0._d,p1._d);
      }
      std::vector<T> coef()const{
        return _d;
      }
      void Print() const{
        for(auto v:_d) printf("%d ",v.val());
        printf("\n");
      }
      template<int MOD>
        static Poly PolyEX(const InvFacBinom<T,MOD>&ifb,int n){ // e^x
          std::vector<T> p(n+1,0);
          for(int i=0;i<=n;i++)p[i]=ifb.ifac[i];
          return p;
        }
      template<int MOD>
        static Poly PolyENegX(const InvFacBinom<T,MOD>&ifb,int n){ // e^{-x}
          std::vector<T> p(n+1,0);
          for(int i=0;i<=n;i++)p[i]=ifb.ifac[i]*(i%2?-1:1);
          return p;
        }
      Poly Rev(int n) const{ // 颠倒[0..n]次的系数
        std::vector<T>r=_d;
        if(n+1>(int)r.size())r.resize(n+1);
        for(int i=0;i<(int)r.size()/2;i++)std::swap(r[i],r[r.size()-1-i]);
        return r;
      }
      Poly Modn(int n) const{ // return (this) mod x^n
        std::vector<T>r=_d;
        if((int)r.size()>n) r.resize(n);
        return r;
      }
      Poly Inv(int n) const{ // return this^{-1}, s.t. this this^{-1} \equiv 1 \pmod{x^n}
        assert(_d[0] != 0);
        Poly r = std::vector<T>{_d[0].inv()};
        for(int pwr=1;pwr<n;pwr*=2){
          r = r.Modn(pwr);
          r = r * (Poly({2}) - r * _d);
        }
        return r.Modn(n);
      }
      Poly Norm() const{ // 清除高位0
        std::vector<T>r=_d;
        while(r.size() > 1 && r.back()==0)r.pop_back();
        return r;
      }
      std::pair<Poly,Poly> Div(const Poly<T>& B) const{ // return  {A / B,A % B}
        const Poly& A=*this;
        int m=B._d.size()-1;
        int n=std::max(A._d.size()-1,B._d.size()-1); // n >= m
        // A=BC+D
        auto C=(A.Rev(n)*(B.Rev(m)).Inv(n-m+1)).Modn(n-m+1).Rev(n-m);
        auto D=(A-B*C).Norm();
        return {C,D};
      }
      std::vector<T> MPE(const std::vector<T>& a) const{ // Multipoint evaluation
        int sz=a.size();
        std::vector<std::vector<Poly > > tree = {{}};
        for(auto v:a)tree[0].push_back(std::vector<T>{-v,1}); // x-ai
        while((tree[0].size() & (tree[0].size()-1)))tree[0].push_back(std::vector<T>{1}); // 1
        while(tree.back().size() > 1){
          std::vector<Poly >row={};
          const auto&b=tree.back();
          for(int i=0;i<(int)b.size()/2;i++) row.push_back(b[i*2]*b[i*2+1]);
          tree.push_back(row);
        }
        std::vector<Poly > h = {Poly(_d)};
        // h[0] 表示 h, 从上向下取mod
        for(int i=tree.size()-1;i>=0;i--){
          std::vector<Poly > nexth = {};
          for(int j=0;j<(int)tree[i].size();j++) nexth.push_back(h[j/2].Div(tree[i][j]).second);
          h = nexth;
        }
        std::vector<T> res;
        for(int i=0;i<sz;i++) res.push_back(h[i]._d[0]);
        return res;
      }
    };
};


using namespace CMM;

// --------------- template ------------------

#include <atcoder/modint>

int main(){
  using namespace std;
  using mint=atcoder::modint998244353;
  const int MOD=998244353;
  using poly=CMM::Poly<mint>;
  int n=20;
  InvFacBinom<mint,MOD> ifb(n);
  poly a=vector<mint> {1,3,5};
  poly b=vector<mint> {2,4,6};
  poly c=a*b;
  c.Print();
  auto [Q,R] = poly(vector<mint>{3,12,28,38,30}).Div(vector<mint>{1,3,5});
  Q.Print();
  R.Print();
  poly f=vector<mint> {3,5,7}; // 7x^2+5x+3
  auto ret=f.MPE(vector<mint> {1,4,9}); // 15 136 615
  for(auto v:ret) printf("%d ",v.val());
  printf("\n");
  return 0;
}


