/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期六 7月 06, 2019 09:27:53 CST
 */

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
const double pi = acos(-1.0);

namespace CG{

  // 浮点误差
  int doublecmp(double x){
    if (fabs(x)<1e-8) return 0;
    else return x<0?-1:1;
  }

  // 浮点误差
  int floatcmp(float x){
    if (fabs(x)<1e-8) return 0;
    else return x<0?-1:1;
  }

  // 向量和
  //
  template<typename T>
    pair<T,T> operator + (pair<T,T> a,pair<T,T> b)  {
      return {a.first+b.first,a.second+b.second};
    }

  // 点差 / 向量差
  template<typename T>
    pair<T,T> operator - (pair<T,T> a,pair<T,T> b)   {
      return {a.first-b.first,a.second-b.second};
    }

  // 长度
  template<typename T>
    double len(pair<T,T> a){
      return sqrt(a.first*a.first+a.first*a.first);
    }

  // 点乘 = |a| |b| cos \theta
  template<typename T>
    T dot(pair<T,T> a,pair<T,T> b){
      return a.first*b.first+a.second*b.second;
    }

  // 叉乘 逆时针面积
  template<typename T>
    T cross(pair<T,T> a,pair<T,T> b){
      return a.first*b.second-a.second*b.first;
    }

  // 点到直线距离
  template<typename T>
    double dis(pair<T,T> p,pair<pair<T,T>,pair<T,T>> line){
      T v = p-line.first;
      T u = line.second - line.first;
      return abs(cross(v,u)/len(u));
    }

  // 线段是否相交
  template<typename T>
    bool segment_cross(pair<pair<T,T>,pair<T,T>> line1,pair<pair<T,T>,pair<T,T>> line2){
      T area0 = cross(line1.second-line1.first,line2.first-line1.first);
      T area1 = cross(line1.second-line1.first,line2.second-line1.first);
      T area2 = cross(line2.second-line2.first,line1.first-line2.first);
      T area3 = cross(line2.second-line2.first,line1.second-line2.first);
      return dcmp(area0)*dcmp2(area1) < 0 && dcmp(area2)*dcmp(area3) < 0;
    }

  // ax+by = cx+dy
  // bx-ay = -(dx-cy)

  // x y         ax+by
  // y -x        bx-ay
  //             c
  //             d

  // ( x y ) ^ -1  (ax+by)
  // ( y -x )      (bx-ay)

  //      1/(x^2+y^2)    (x     y)  (ax+by)
  //                     (y     -x)  (bx-ay)

  // 1/(x^2+y^2) (ax^2+2bxy-ay^2)
  //             (2axy+by^2 -bx^2)
  // 等长度 入射反射
  pair<double,double> reflect(pair<double,double> inarrow, pair<double,double> surface){
    auto [a,b] = inarrow; //
    auto [x,y] = surface; //
    double fm = x*x+y*y;
    double fz0 = a*x*x-a*y*y+2*b*x*y;
    double fz1 = b*y*y-b*x*x+2*a*x*y;
    return {fz0/fm,fz1/fm};
  }
  template<typename T,typename U>
    void printPair(pair<T,U> tu){
      cout<<tu.first<<" "<<tu.second<<endl;
    }
}


int main(){
  pair<ll,ll> A = {0,1};
  pair<ll,ll> B = {1,0};
  pair<ll,ll> O = {0,0};
  using CG::operator-;
  printf("%lld\n",CG::cross(A-O,B-O));
  printf("%lld\n",CG::cross(B-O,B-O));
  printf("%lld\n",CG::dot(A-O,B-O));
  printf("%lld\n",CG::dot(A-O,B-O));

  CG::printPair(CG::reflect({2,-2},{1,0}));
  CG::printPair(CG::reflect({2,0},{3,4}));

  return 0;
}

/*
 *
 * hash prime
 61,83,113,151,211,281,379,509683,911
 1217,1627,2179,2909,3881,6907,9209
 12281,16381,21841,29123,38833,51787,69061,92083
 122777,163729,218357,291143,388211,517619,690163,999983
 1226959,1635947,2181271,2908361,3877817,5170427,6893911,9191891
 12255871,16341163,21788233,29050993,38734667,51646229,68861641,91815541
 122420729,163227661,217636919,290182597,386910137,515880193,687840301,917120411
 1000000007,1000000009
 * */

