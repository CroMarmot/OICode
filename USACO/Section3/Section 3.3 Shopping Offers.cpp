/*
ID: 10157591
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("shopping.in");
ofstream outc("shopping.out");
int n;
int data[1010][20]={0};
int cur = 1;
int bb;
int g[3][10]={0};

int grepnum = 0;
int grepres[1010][10]={0};
int contain(int v){
  int i;
  for(i=0;i<bb;i++)
    if(g[0][i] == v)
      return i;
  return -1;
}
void put(int index){
  grepres[grepnum][5] = data[index][data[index][0]*2+1];
  int i;
  for(i=0;i<data[index][0];i++){
    int ii=i*2+1;
    grepres[grepnum][contain(data[index][ii])] = data[index][ii+1];
  }
  grepnum++;
}
void grep(){
  int i;
  for(i=0;i<n;i++){
    int j;
    for(j=0;j<data[i][0];j++){
      if(contain(data[i][j*2+1]) == -1)
        continue;
    }
    put(i);
  }
}

int calc[10][10][10][10][10];

int minn(int v1,int v2){
  return v1<v2?v1:v2;
}
void build(int index){
  int i;
  int a,b,c,d,e;
  for(a=0;a<=g[1][0];a++)
    for(b=0;b<=g[1][1];b++)
      for(c=0;c<=g[1][2];c++)
        for(d=0;d<=g[1][3];d++)
          for(e=0;e<=g[1][4];e++){
            if(calc[a][b][c][d][e]!=-1){
              for(i=1;i<=5;i++){
                int newa = a + grepres[index][0];
                int newb = b + grepres[index][1];
                int newc = c + grepres[index][2];
                int newd = d + grepres[index][3];
                int newe = e + grepres[index][4];
                if(
                    newa <=g[1][0] &&
                    newb <=g[1][1] &&
                    newc <=g[1][2] &&
                    newd <=g[1][3] &&
                    newe <=g[1][4]){
                  calc[newa][newb][newc][newd][newe] = minn(
                    calc[newa][newb][newc][newd][newe],
                    calc[a][b][c][d][e]+grepres[index][5]);
                }else
                  break;
              }

            }
          }
  grepres[index][0];


}

int search(int a,int b,int c,int d,int e){
  int i;
  for(i=0;i<grepnum;i++){
    int newa = a - grepres[i][0];
    int newb = b - grepres[i][1];
    int newc = c - grepres[i][2];
    int newd = d - grepres[i][3];
    int newe = e - grepres[i][4];
    if(
        newa >=0 &&
        newb >=0 &&
        newc >=0 &&
        newd >=0 &&
        newe >=0 ){
      int res = search(newa,newb,newc,newd,newe);
      if(res != -1){
        res += grepres[i][5];
        if(res < calc[a][b][c][d][e])
          calc[a][b][c][d][e] = res;

      }
    }
  }
  return calc[a][b][c][d][e];
}

int main(){
  inc>>n;
  int i;
  for(i=0;i<n;i++){
    inc>>data[i][0];
    int j;
    for(j=1;j<=2*data[i][0]+1;j++){
      inc>>data[i][j];
    }
  }
  inc>>bb;
  for(i=0;i<bb;i++){
    inc>>g[0][i]>>g[1][i]>>g[2][i];
  }
  grep();

  // for(i=0;i<grepnum;i++){
  //   int j;
  //   for(j=0;j<6;j++)
  //     cout<<grepres[i][j]<<" ";
  //   cout<<endl;
  // }

  int a,b,c,d,e;
  for(a=0;a<=5;a++)
    for(b=0;b<=5;b++)
      for(c=0;c<=5;c++)
        for(d=0;d<=5;d++)
          for(e=0;e<=5;e++)
            calc[a][b][c][d][e] = -1;

  for(a=0;a<=g[1][0];a++)
    for(b=0;b<=g[1][1];b++)
      for(c=0;c<=g[1][2];c++)
        for(d=0;d<=g[1][3];d++)
          for(e=0;e<=g[1][4];e++)
            calc[a][b][c][d][e] = a*g[2][0]+b*g[2][1]+c*g[2][2]+d*g[2][3]+e*g[2][4];

  for(i=0;i<grepnum;i++){
    build(i);
  }
  // outc<<search(g[1][0],g[1][1],g[1][2],g[1][3],g[1][4])<<endl;
  outc<<calc[g[1][0]][g[1][1]][g[1][2]][g[1][3]][g[1][4]]<<endl;

  return 0;
}
