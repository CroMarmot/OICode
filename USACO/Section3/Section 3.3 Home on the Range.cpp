/*
ID: 10157591
PROG: range
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("range.in");
ofstream outc("range.out");
int range[300][300]={0};

int cntsquare(int n){
  int i,j;
  int res = 0;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        range[i][j] = range[i][j] && range[i+1][j] && range[i][j+1] && range[i+1][j+1];
        res += range[i][j];
    }
  return res;
}

int main(){
  int n;
  inc >> n;
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
      char tmp;
      inc>>tmp;
      range[i][j]=tmp-'0';
    }

  int width = 1;
  int ret;
  while(ret = cntsquare( n - width ))
    outc<<++width<<" "<<ret<<endl;
  return 0;
}
