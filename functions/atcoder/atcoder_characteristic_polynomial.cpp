#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
typedef long long ll;
using mint=atcoder::modint998244353;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
ll read(){ll v;scanf("%lld",&v);return v;}

// T is your custom modint
template<class T> // det(Ix-A)
std::vector<T> characteristic_polynominal(std::vector<std::vector<T>> A){ // copy(need modify)
  int n = A.size();
  if(n == 0) return vector<T>{1};
  assert(n == A[0].size());
  // 先转化成 上 海森堡 矩阵
  rep(j,0,n-1) { // 列
    rep(i,j+1,n) if (A[i][j] != 0) { // 取一个j列 行主元 非0的行
      swap(A[j+1], A[i]);
      rep(k,0,n) swap(A[k][j+1], A[k][i]);
      break;
    }
    if (A[j+1][j]!=0){ // 基础行/列变换,[i=j+2..n][j]置为0
      mint ajj_inv = A[j+1][j].inv();
      rep(i,j+2,n){
        mint c = A[i][j] * ajj_inv;
        rep(k,j,n) A[i][k  ] -= A[j+1][k] * c; // row[i]  -=A[i][j]*A[j+1][j].inv()*row[j+1]
        rep(k,0,n) A[k][j+1] += A[k  ][i] * c; // col[j+1]+=A[i][j]*A[j+1][j].inv()*col[i]
      }
    }
  }
  // 暴力展开最后一列
  std::vector<std::vector<T> > f(n+1); // 1-index
  f[0] = {1}; // |[0x0]| = 1
  // f[1-index],A[0-index]:
  //    f[i+1] = (x-A[i][i]) f[i] + sum (-A[j=i-1..0][i] * (prod -A[_=i..j+1][_-1]) * f[j] * (-1)^{i-j})
  //    f[i+1] = (x-A[i][i]) f[i] - sum ( A[j=i-1..0][i] * (prod  A[_=i..j+1][_-1]) * f[j])
  //    f[i+1] = x*f[i] - sum ( A[j=i..0][i] * (prod A[_=i..j+1][_-1]) * f[j])
  rep(i,0,n) {
    f[i+1].push_back(0);
    rep(j,0,size(f[i])) f[i+1].push_back(f[i][j]); // *x
    T prod=1;
    per(j,0,i+1){ // i..0
      T t = prod*A[j][i];
      rep(k,0,size(f[j])) f[i+1][k] -= f[j][k]*t;
      if(j) prod *= A[j][j-1];
    }
  }
  return f[n];
}

int main(){
  // https://judge.yosupo.jp/problem/characteristic_polynomial
  // https://judge.yosupo.jp/submission/187263
  int n = read(); // <= 500
  vector matrix(n,vector<mint>(n,0));
  rep(i,0,n) rep(j,0,n) matrix[i][j]=read();
  auto res = characteristic_polynominal(matrix);
  rep(i,0,n+1) printf("%d ",res[i].val());
  return 0;
}
