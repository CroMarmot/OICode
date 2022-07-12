/*
ID: 10157591
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("rockers.in");
ofstream outc("rockers.out");

int res[30][30]={0}; // [m][left] = num t
int newres[30][30]={0}; // [m][left] = num t
int visit[30][30]={0};

int list[500][2]={0};

int maxx(int v1,int v2){
  return v1>v2?v1:v2;
}

int main(){
  int N,T,M;
  inc>>N>>T>>M;
  int rear=1;
  visit[0][0]=1;
  list[0][0]=0;
  list[0][1]=0;

  int i,j,k;
  for(i=0;i<N;i++){
    int len;
    inc>>len;

    for(j=0;j<=M;j++){
      for(k=0;k<=T;k++){
        newres[j][k]=0;
      }
    }

    for(j=rear-1;j>=0;j--){
      int m = list[j][0],left=list[j][1];
      int oldt = res[m][left];
      if(left >= len){
        int newleft = left-len;
        newres[m][newleft] = maxx(newres[m][newleft],oldt+1);
        if(!visit[m][newleft]){
          visit[m][newleft]=1;
          list[rear][0]=m;
          list[rear][1]=newleft;
          rear++;
        }
      }else if(T >= len && m<=M){
        int newm = m+1;
        int newleft = T-len;
        newres[newm][newleft] = maxx(newres[newm][newleft],oldt+1);
        if(!visit[newm][newleft]){
          visit[newm][newleft]=1;
          list[rear][0]=newm;
          list[rear][1]=newleft;
          rear++;
        }
      }
    }

    for(j=0;j<=M;j++){
      for(k=0;k<=T;k++){
        res[j][k]=maxx(res[j][k],newres[j][k]);
      }
    }
  }
  int output = 0 ;
  for(j=0;j<=M;j++){
    for(k=0;k<T;k++){
      output = maxx(output,res[j][k]);
    }
  }
  outc<<output<<endl;

  return 0;
}
