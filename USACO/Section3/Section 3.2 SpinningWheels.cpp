/*
ID: 10157591
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("spin.in");
ofstream outc("spin.out");
int speed[5];
int open[5][361]={0};
int light[361];
bool check(int times){
  int i,j=0;
  for(i=0;i<360;i++)
    light[(i+times*speed[j])%360] = open[j][i];
  for(j=1;j<5;j++){
    for(i=0;i<360;i++){
      light[(i+times*speed[j])%360] &= open[j][i];
    }
  }
  for(i=0;i<360;i++)
    if(light[i])
      return true;
  return false;
}
int main()
{
  int i;
  for(i=0;i<5;i++){
    inc>>speed[i];
    int tmp;
    inc>>tmp;
    while(tmp-->0){
      int st,len;
      inc>>st>>len;
      while(len>=0){
        open[i][(st+len)%360]=1;
        len--;
      }
    }
  }
  for(i=0;i<360;i++)
    if(check(i)){
      outc<<i<<endl;
      return 0;
    }
  outc<<"none"<<endl;
  return 0;
}
