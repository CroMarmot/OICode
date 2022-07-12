/*
ID: 10157591
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("ratios.in");
ofstream outc("ratios.out");
int jz[4][3];

int gcd(int a,int b){
  return a<0?gcd(-a,b):(b<0?gcd(a,-b):(b == 0?a:(a<b?gcd(b,a):(a%b?gcd(b,a%b):b))));
}

void gcd4(int &a,int &b,int &c,int &d){
  int g=gcd(gcd(a,b),gcd(c,d));
  a=a/g;
  b=b/g;
  c=c/g;
  d=d/g;
}

void colclear(int i, int j){
  int mul=jz[i][j],k;
  for(k=0;k<4;k++){
    jz[k][j] *= jz[i][i];
    jz[k][j] -= jz[k][i]*mul;
  }
  gcd4(jz[0][j],jz[1][j],jz[2][j],jz[3][j]);
}

void clear(int i){
  int j,k;
  if(!jz[i][i]){
    for(j=i+1;j<3;j++)
      if(jz[i][j])
        break;
    if(j == 3)
      return ;
    for(k=i;k<4;k++){
      int tmp = jz[k][i];
      jz[k][i] = jz[k][j];
      jz[k][j] = tmp;
    }
  }
  if(!jz[i][i])
    return ;
  for(j=i+1;j<3;j++)
    colclear(i,j);
}

int main(){
  int i,j;
  for(i=0;i<3;i++)
      inc>>jz[3][i];
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      inc>>jz[i][j];
  int A =
    jz[0][0]*jz[1][1]*jz[2][2]+
    jz[0][1]*jz[1][2]*jz[2][0]+
    jz[0][2]*jz[1][0]*jz[2][1]
    -jz[0][0]*jz[1][2]*jz[2][1]
    -jz[0][1]*jz[1][0]*jz[2][2]
    -jz[0][2]*jz[1][1]*jz[2][0];
  if(A == 0){
    outc<<"NONE"<<endl;
    return 0;
  }
  clear(0);
  clear(1);
  colclear(2,1);
  colclear(2,0);
  colclear(1,0);

  int ans[4] = {
    jz[3][0]*jz[1][1]*jz[2][2],
    jz[0][0]*jz[3][1]*jz[2][2],
    jz[0][0]*jz[1][1]*jz[3][2],
    jz[0][0]*jz[1][1]*jz[2][2]
  };

  if(ans[0] <= 0 && ans[1] <= 0 && ans[2] <= 0 && ans[3] <= 0){
    ans[0]=-ans[0];
    ans[1]=-ans[1];
    ans[2]=-ans[2];
    ans[3]=-ans[3];
  }

  if(ans[0] < 0 || ans[1] < 0 || ans[2] < 0 || ans[3] < 0){
    outc<<"NONE"<<endl;
    return 0;
  }

  gcd4(ans[0],ans[1],ans[2],ans[3]);
  outc<<ans[0]<<" ";
  outc<<ans[1]<<" ";
  outc<<ans[2]<<" ";
  outc<<ans[3]<<endl;
  return 0;
}
