/*
ID: 10157591
PROG: fence6
LANG: C++
*/
#include <iostream>
#include <fstream>
#define SUPERMAX 100000

using namespace std;
ifstream inc("fence6.in");
ofstream outc("fence6.out");

int n;

int line[110];
int linkto[2][110][110];
int G[110][110]={0};
int dist[110][110]={0};

int minn(int v1,int v2){
  return v1<v2?v1:v2;
}

bool samepoint(int a,int b,int c){
  bool binleft=false,binright=false,cinleft=false,cinright=false;
  int i;
  for(i=1;i<=linkto[0][a][0];i++){
    if(b == linkto[0][a][i])
      binleft = true;
    if(c == linkto[0][a][i])
      cinleft = true;
  }
  for(i=1;i<=linkto[1][a][0];i++){
    if(b == linkto[1][a][i])
      binright = true;
    if(c == linkto[1][a][i])
      cinright = true;
  }
  if(binleft && cinleft)
    return true;
  if(binright && cinright)
    return true;
  return false;
}

int main(){
  inc>>n;
  int i,j;
  int index,lenth,lnum,rnum;
  for(i=0;i<n;i++){
    inc>>index>>lenth>>lnum>>rnum;
    line[index]=lenth;
    linkto[0][index][0]=lnum;
    linkto[1][index][0]=rnum;
    for(j=0;j<lnum;j++)
      inc>>linkto[0][index][j+1];
    for(j=0;j<rnum;j++)
      inc>>linkto[1][index][j+1];
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=linkto[0][i][0];j++)
      G[i][linkto[0][i][j]] = line[i]+line[linkto[0][i][j]];
    for(j=1;j<=linkto[1][i][0];j++)
      G[i][linkto[1][i][j]] = line[i]+line[linkto[1][i][j]];
  }

  for(i=1;i<=n;i++)
    for(j=i;j<=n;j++){
      if(G[i][j] == 0)
        G[i][j] = SUPERMAX;
      dist[i][j] = dist[j][i] = G[j][i] = G[i][j];
    }
  // for(i=1;i<=n;i++){
  //   for(j=1;j<=n;j++){
  //     cout<<dist[i][j]<<"\t";
  //   }
  //   cout<<endl;
  // }

  int k;
  int res = SUPERMAX;

  for(k=1;k<=n;k++){
    for(i=1;i<k;i++)
      for(j=i+1;j<k;j++){
        if(res > dist[i][j]+G[i][k]+G[k][j]){
          // fuck 2 3 8
          if(samepoint(i,j,k))
            continue;
          // cout<<i<<" "<<j<<" "<<k<<" | "<<dist[i][j]<<","<<G[i][k]<<","<<G[k][j]<<endl;
          res = minn(res, dist[i][j]+G[i][k]+G[k][j]);

        }
      }
    for(i=1;i<=n;i++)
      for(j=i+1;j<=n;j++){
        dist[j][i] = dist[i][j] = minn(dist[i][j],dist[i][k]+dist[k][j]);
      }
  }
  outc<<res/2<<endl;
}

// user line center point to construct new vertex and new edge
