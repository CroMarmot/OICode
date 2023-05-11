#include <bits/stdc++.h>
using namespace std;

// 返回的 [x,y,z] 满足 a*x+b*y=z=gcd(a,b)
template<class T>
array<T,3> exgcd(T a,T b){
  if(b==0) return {1,0,a};
  auto [x,y,z] = exgcd(b,a%b);
  return {y,x-(a/b)*y,z};
}

int main(){
  int a=31,b=7;
  auto [x,y,z] = exgcd(a,b);
  printf("%d*%d+%d*%d=%d\n",a,x,b,y,z);
  return 0;
}
