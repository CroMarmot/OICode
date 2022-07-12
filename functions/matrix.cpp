#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair

namespace Matrix {
  static ll** gen(int sz_1,int sz_2){
    assert(sz_1 > 0 && sz_2 > 0);
    ll **ret = new ll* [sz_1];
    rep(i,0,sz_1){
      ret[i]=new ll[sz_2];
    }
    return ret;
  }
  // I1[sz_1][sz_2]*I2[sz_2][sz_3] = O[sz_1][sz_3]
  static void mul(int sz_1,int sz_2,int sz_3,ll ** I1,ll **I2,ll **O1,ll mod){
    assert(sz_1 > 0 && sz_2 > 0 && sz_3 >0);
    assert(I1 != NULL && I2 != NULL && O1 != NULL);
    ll ** tmp = new ll* [sz_1]; // 临时数组用于支持 mul(A,A,A)形势
    rep(i,0,sz_1){
      tmp[i]=new ll[sz_3];
    }
    rep(i,0,sz_1){
      rep(j,0,sz_3){
        tmp[i][j] = 0;
        rep(k,0,sz_2){
          (tmp[i][j]+=I1[i][k]*I2[k][j])%=mod;
        }
      }
    }
    rep(i,0,sz_1){
      rep(j,0,sz_3){
        O1[i][j]=tmp[i][j];
      }
      delete [] tmp[i];
    }
    delete [] tmp;
  }
  static void print(int sz_1,int sz_2,ll **I1){
    rep(i,0,sz_1){
      rep(j,0,sz_2){
        printf("%lld\t",I1[i][j]);
      }
      printf("\n");
    }
  }
};

int main(){
  auto m1 = Matrix::gen(2,3);
  auto m2 = Matrix::gen(3,4);
  auto m3 = Matrix::gen(2,4);
  m1[0][2]=3;
  m1[1][1]=6;
  m1[1][0]=2;

  m2[0][1]=5;
  m2[1][1]=6;
  m2[1][2]=8;
  m2[2][2]=9;
  Matrix::mul(2,3,4,m1,m2,m3,29);
  cout<<"m1"<<endl;
  Matrix::print(2,3,m1);
  cout<<"m2"<<endl;
  Matrix::print(3,4,m2);
  cout<<"m3"<<endl;
  Matrix::print(2,4,m3);
  return 0;
}
