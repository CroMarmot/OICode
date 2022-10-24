#include <bits/stdc++.h>
#include <atcoder/modint>
using mint=atcoder::modint998244353;
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back

namespace MatrixVec{
  template<class T>
    T det(const vector<vector<T>>& _a){ // 行列式 高斯消元
      auto a=_a;
      auto n=a.size();
      if(n==0)return 1;
      assert(n==a[0].size());
      T ans=1;
      T neg=-1; // 除法慢 少用除法
      rep(j,0,n){
        rep(i,j,n)if(a[i][j]!=0){ // >=j行中找j列首个非零值,做行交换
          if(i!=j){
            std::swap(a[i],a[j]);
            ans*=neg;
          }
          break;
        }
        ans*=a[j][j];// 主元
        if(ans==0)return 0;
        T t=T(1)/a[j][j]; // 少做除法
        rep(k,j,n)a[j][k]*=t;
        rep(i,j+1,n)per(k,j,n)a[i][k]-=a[i][j]*a[j][k]; // 行变换, 注意per顺序
      }
      return ans;
    }

  // 行列式 高斯消元 解增广矩阵, 答案全为mint
  // {是否成功, 消元后的增广矩阵(左边nxn 为单位矩阵)}
  pair<bool,vector<vector<mint>>> solvemint(const vector<vector<mint>>& _a){
    auto a=_a;
    auto n=a.size(); // 行
    if(n==0) return {true,{}};
    assert(n < a[0].size()); // 增广
    rep(j,0,n){
      rep(i,j,n)if(a[i][j]!=0){ // >=j行中找j列首个非零值,做行交换
        if(i!=j) std::swap(a[i],a[j]);
        break;
      }
      if(a[j][j]==0) return {false,{}};
      mint t=a[j][j].inv(); // 少做除法
      per(k,j,a[j].size()) a[j][k]*=t;
      rep(i,0,n)if(i!=j)per(k,j,a[i].size())a[i][k]-=a[i][j]*a[j][k]; // 行变换, 注意per顺序
    }
    return {true,a};
  }

  // 行列式 高斯消元 解增广矩阵, 答案全为整数
  // {是否成功, 消元后的增广矩阵(左边nxn 为单位矩阵)}
  pair<bool,vector<vector<ll>>> solvell(const vector<vector<ll>>& _a){
    auto a=_a;
    auto n=a.size(); // 行
    if(n==0) return {true,{}};
    assert(n < a[0].size()); // 增广
    rep(j,0,n){
      rep(i,j,n)if(a[i][j]!=0){ // >=j行中找j列首个非零值,做行交换
        if(i!=j) std::swap(a[i],a[j]);
        break;
      }
      if(a[j][j]==0) return {false,{}};
      per(k,j,a[j].size()){ // 保证答案全为整数, 注意顺序
        if(a[j][k] % a[j][j] !=0) return {false,{}};
        a[j][k]/=a[j][j];
      }
      rep(i,0,n) if(i!=j)per(k,j,a[i].size())a[i][k]-=a[i][j]*a[j][k]; // 行变换, 注意per顺序
    }
    return {true,a};
  }

  template<class T>
    vector<vector<T>> mul(const vector<vector<T>>& a,const vector<vector<T>>&b){// 矩阵乘法
      auto n=a.size();
      if(n==0)return {};
      auto K=a[0].size();
      assert(K==b.size());
      int m=0;
      if(K)m=b[0].size();
      auto r=vector(n,vector<mint>(m,0));
      rep(i,0,n)rep(j,0,m)rep(k,0,K)r[i][j]+=a[i][k]*b[k][j];
      return r;
    }

  template<class T>
    vector<vector<T>> pow(vector<vector<T>> a,ll pwr){ // 矩阵幂次
      auto n=a.size();
      if(n==0)return {};
      assert(n==a[0].size());
      auto r=vector(n,vector<T>(n,0));
      rep(i,0,n)r[i][i]=1;
      while(pwr){
        if(pwr%2)r=mul(r,a);
        a=mul(a,a);
        pwr/=2;
      }
      return r;
    }

  void printmint(const vector<vector<mint>>& a){ // 打印mint
    auto n=a.size();
    if(n==0)return ;
    int m=a[0].size();
    if(m==0)return ;
    printf("[\n");
    rep(i,0,n)rep(j,0,m)printf("%d%c",a[i][j].val()," \n"[j==m-1]);
    printf("]\n");
  }
  template<class T>
  void print(const vector<vector<T>>& a){ // 打印 int/long long/bool
    auto n=a.size();
    if(n==0)return ;
    int m=a[0].size();
    if(m==0)return ;
    printf("[\n");
    rep(i,0,n)rep(j,0,m)printf("%lld%c",(ll)a[i][j]," \n"[j==m-1]);
    printf("]\n");
  }
};

int main(){
  vector<vector<mint>> A={{2,1},{3,4}};
  vector<vector<mint>> B={{2,3},{4,5}};
  printf("det(A)=%d\n",MatrixVec::det(A).val());
  printf("A=");
  MatrixVec::printmint(A);
  printf("B=");
  MatrixVec::printmint(B);
  auto C=MatrixVec::mul(A,B);
  printf("A*B=");
  MatrixVec::printmint(C);
  return 0;
}


