/*
ID: 10157591
PROG: game1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("game1.in");
ofstream outc("game1.out");
int val[110]={0};
int res[110][110]={0};
int cnt[110][110]={0};
int minn(int v1,int v2){
  return v1<v2?v1:v2;
}
int f(int l,int r){
  if(res[l][r])
    return res[l][r];
  if(l == r)
    return res[l][r]=val[l];
  return res[l][r] = cnt[l][r] - minn(f(l+1,r),f(l,r-1));
}
int main(){
  int n;
  inc>>n;
  int i,j;
  for(i=0;i<n;i++)
    inc>>val[i];
  for(i=0;i<n;i++){
    cnt[i][i] = val[i];
    for(j=i+1;j<n;j++){
      cnt[i][j]=cnt[i][j-1]+val[j];
    }
  }
  outc<<f(0,n-1)<<" "<<cnt[0][n-1] - f(0,n-1)<<endl;
  return 0;
}
