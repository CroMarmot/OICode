#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
typedef long long ll;
using mint=atcoder::modint998244353;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
ll read(){ll v;scanf("%lld",&v);return v;}

template<class T> // det(Ix-A), T is your custom modint
std::vector<T> characteristic_polynominal(std::vector<std::vector<T>> A){ // copy(need modify), A[0-index]
  int n = A.size();
  if(n == 0) return vector<T>{1};
  assert(n == (int)A[0].size());
  // 先转化成 上 海森堡 矩阵
  rep(j,0,n-1) { // 列
    rep(i,j+1,n) if (A[i][j] != 0) { // 取一个j列 行主元 非0的行
      swap(A[j+1], A[i]); // 交换
      rep(k,0,n) swap(A[k][j+1], A[k][i]); // 列交换
      break;
    }
    if (A[j+1][j]!=0){ // 基础行/列变换,[i=j+2..n][j]置为0
      T ajj_inv = A[j+1][j].inv();
      rep(i,j+2,n){
        T c = A[i][j] * ajj_inv;
        rep(k,j,n) A[i][k  ] -= A[j+1][k] * c; // row[i]  -=A[i][j]*A[j+1][j].inv()*row[j+1]
        rep(k,0,n) A[k][j+1] += A[k  ][i] * c; // col[j+1]+=A[i][j]*A[j+1][j].inv()*col[i]
      }
    }
  }
  // 暴力展开最后一列
  std::vector<std::vector<T> > f(n+1); // 1-index
  f[0] = {1}; // |[0x0]| = 1
  // f[i+1] = x*f[i] - sum ( A[j=i..0][i] * (prod A[_=i..j+1][_-1]) * f[j])
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

template<class T> // det(Ax+B), T is your custom modint
std::vector<T> matrix_det(std::vector<std::vector<T>> A,std::vector<std::vector<T>>B){ // copy(need modify), A[0-index]x+B
  int n = A.size();
  auto op=[&](auto fn){fn(A);fn(B);}; // 同时操作A,B
  // Ax+B => LARx + LBR => Ix + B' 的形式
  int mul=0; // det(Ix+B') = det(Ix+newB)/x^mul
  T coef=1; // 从矩阵中统一提取出来的系数?
  rep(i,0,n) {
    // 行变换 让A[i][i]!=0
    auto _=[&](){ rep(j,i,n) if(A[j][i] != 0){ // A,B 同时行变换, 让A[i][i] != 0
      op([&](auto &M){ swap(M[i],M[j]);});
      if(i!=j) coef*=-1;
      break;
    } };
    if(A[i][i]==0) { // i列全为不带x, A[0~n][i]==0, 则i列乘上x, 最后det/x
      rep(j,0,n) swap(A[j][i],B[j][i]);
      mul++;
      _();
    }
    if(A[i][i]==0) return vector<T>(n+1,0); // 该列A,B全是0
    T inv=A[i][i].inv();
    coef=coef*A[i][i];
    // A的[i][i] 行变成 1
    op([&](auto&M){ rep(j,0,n) M[i][j]=M[i][j]*inv; });
    rep(j,0,n) if(j!=i and A[j][i]!=0) { // if(A[j][i]!=0) { 把A中i列上，除了i行的全行变换 变成0
      T x=A[j][i];
      op([&](auto&M){ rep(k,0,n) M[j][k]-=M[i][k]*x; });
    }
    rep(j,i+1,n) if(A[i][j] != 0){ // 列变换 可以省略吗？省略了似乎不能那样搬列了?
      T x=A[i][j];
      op([&](auto&M){ rep(k,0,n) M[k][j]-=M[k][i]*x; });
    }
  }
  // Ix+B => Ix-B
  rep(i,0,n) rep(j,0,n) B[i][j]=-B[i][j];
  auto cp=characteristic_polynominal(B); // 即求B的特征方程
  vector<T> ans(n+1,0);
  rep(i,mul,n+1) ans[i-mul]=cp[i]*coef;
  return ans;
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
