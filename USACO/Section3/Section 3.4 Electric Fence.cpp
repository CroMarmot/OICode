/*
ID: 10157591
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("fence9.in");
ofstream outc("fence9.out");

int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}

int triangle(int n,int m){
  return ((m-1)*(n-1)+1-gcd(m,n))/2;
}

int main(){
  int n,m,p;
  inc>>n>>m>>p;
  int res;
  if(n == p){
    res = triangle(n,m);
  }else if(n<p){
    res = triangle(n,m)+m-1+triangle(p-n,m);
  }else{
    res = triangle(n,m)-triangle(n-p,m)-gcd(n-p,m)+1;
  }
  outc<<res<<endl;
  return 0;
}
