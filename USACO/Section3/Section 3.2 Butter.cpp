/*
ID: 10157591
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream inc("butter.in");
ofstream outc("butter.out");

int cow[500];
int dist[801][801];

int minn(int a,int b){
  return a<b?a:b;
}

int d(int i,int j){
  return i>j?dist[j][i]:dist[i][j];
}

int n;
int calc(int i){
  int cnt=0;
  for(int j=0;j<n;j++)
    cnt += d(i,cow[j]);
  return cnt;
}



int main(){
  int p,c;
  inc>>n>>p>>c;
  int i,j;
  for(i=1;i<=p;i++)
    for(j=1;j<=p;j++)
      dist[i][j]=-1;
  for(i=1;i<=p;i++)
    dist[i][i]=0;

  for(i=0;i<n;i++)
    inc>>cow[i];
  for(i=0;i<c;i++){
    int a,b,length;
    inc>>a>>b>>length;
    dist[a][b] = length;
    dist[b][a] = length;
  }

  for(int k=1;k<=p;k++)
    for(i=1;i<=p;i++){
      if(k==i || d(i,k) == -1)
        continue;
      for(j=i+1;j<=p;j++){
        if(k == j || d(j,k)==-1)
          continue;
        int ret = d(i,k)+d(j,k);
        if(dist[i][j] == -1 || ret < dist[i][j])
          dist[i][j] = ret;
      }
    }

  // for(i=1;i<=p;i++){
  //   for(j=1;j<=p;j++){
  //     cout<<dist[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  int res = calc(1);
  for(i=2;i<=p;i++)
    res = minn(res,calc(i));

  outc<<res<<endl;

  return 0;
}

