/*
ID: 10157591
PROG: stall4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream inc("stall4.in");
ofstream outc("stall4.out");

bool cow[210][210]={0}; // cow stall
int cowback[210]={0}; // stall -> cow

bool visit[210]={0};

int n,m;

bool bpg(int index){
  int i,j;
  for(i=1;i<=m;i++){
    if( cow[index][i]==true && !visit[i] ){
      visit[i] = true;
      if(cowback[i] == 0 || bpg(cowback[i])){
        cowback[i] = index;
        return true;
      }
    }
  }
  return false;
}

int main(){
  inc>>n>>m;
  int i,j;
  for(i=1;i<=n;i++){
    int num;
    inc>>num;
    for(j=0;j<num;j++){
      int tmp;
      inc>>tmp;
      cow[i][tmp] = true;
    }
  }

  int ans=0;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++)
      visit[j]=0;
    if(bpg(i))
      ans++;
  }
  outc<<ans<<endl;

  return 0;
}
