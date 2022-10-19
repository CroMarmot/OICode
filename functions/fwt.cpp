#include <bits/stdc++.h>
#include "./modint.cpp"
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back

// ---------- fwt ----------
using MODINT::modint;
namespace FWT{
  void ForT(vector<modint> &f,int flag = 1/* 1:正变换,-1:逆变换 */) {
    int n = f.size();
    for (int l=1; l<n; l*=2){
      for (int s=0; s<n; s+=2*l){
        rep(i,s,s+l){ // [i..i+l)<=>[i+l..i+2l)
          f[i+l] += f[i] * flag;
        }
      }
    }
  }

  void IForT(vector<modint> &f) {ForT(f, -1);}

  vector<modint> or_convolution(vector<modint> &v0, vector<modint> &v1){
    const int sz = v0.size();
    ForT(v0);
    ForT(v1);
    vector<modint> v2(sz,0);
    rep(i,0,sz) v2[i] = v0[i] * v1[i];
    IForT(v2);
    return v2;
  }

  void FandT(vector<modint> &f, int flag = 1/* 1:正变换,-1:逆变换 */) {
    int n = f.size();
    for (int l=1; l<n; l*=2){
      for (int s=0; s<n; s+=2*l){
        rep(i,s,s+l){ // [i..i+l)<=>[i+l..i+2l)
          f[i] += f[i+l] * flag;
        }
      }
    }
  }
  void IFandT(vector<modint> &f) {FandT(f, -1);}

  vector<modint> and_convolution(vector<modint> &v0, vector<modint> &v1){
    const int sz = v0.size();
    FandT(v0);
    FandT(v1);
    vector<modint> v2(sz,0);
    rep(i,0,sz) v2[i] = v0[i] * v1[i];
    IFandT(v2);
    return v2;
  }

  modint inv2 = modint(2).inv();
  void FWHT(vector<modint> &f, modint flag = 1 /* 1: 正变换, 1/2: 逆变换*/) {
    int n = f.size();
    for(int l=1; l<n; l*=2){ // len
      for (int s=0; s<n; s+=2*l){ // start pos
        rep(i,s,s+l){ // [i..i+l) <=> [i+l,i+2l)
          auto U = f[i];
          auto T = f[i+l];
          f[i]   = (U+T)*flag;
          f[i+l] = (U-T)*flag;
        }
      }
    }
  }
  void IFWHT(vector<modint> &f) {FWHT(f, inv2);}
  void FxorT(vector<modint> &f,int flag = 1) {FWHT(f, flag);}
  void IFxorT(vector<modint> &f) {IFWHT(f);}

  vector<modint> xor_convolution(vector<modint> &v0, vector<modint> &v1){
    const int sz = v0.size();
    FxorT(v0);
    FxorT(v1);
    vector<modint> v2(sz,0);
    rep(i,0,sz) v2[i] = v0[i] * v1[i];
    IFxorT(v2);
    return v2;
  }
};
// ---------- fwt ----------

void print(vector<modint> &arr){
  for(auto &v:arr) printf("%d ", v.val());
  printf("\n");
}

int main(){
  // 长度2的幂次
  const vector<modint> A0 = {1,2,3,0};
  const vector<modint> B0 = {4,5,6,0};

  // --- or ---
  {
    auto A = A0;
    auto B = B0;
    auto C = FWT::or_convolution(A,B);
    print(C);
  }
  // --- and ---
  {
    auto A = A0;
    auto B = B0;
    auto C = FWT::and_convolution(A,B);
    print(C);
  }
  // --- xor ---
  {
    auto A = A0;
    auto B = B0;
    auto C = FWT::xor_convolution(A,B);
    print(C);
  }
  return 0;
}

