/*
ID: 10157591
PROG: snail
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "snail";

const int EMPTY = 0;
const int BLOCK = 1;
const int FOOTP = 2;

// 120*120
//
// from left up corner
//
// move until visit old footprint
// turn while meet wall

int matrix[200][200];

int deri[]={1,0,-1,0};
int derj[]={0,1,0,-1};

int ans = 0;

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}
int n,b;

void dfs(int pi,int pj,int v){
  rep(direction,0,4){
    int di = deri[direction];
    int dj = derj[direction];
    int newi = pi+di;
    int newj = pj+dj;
    if(matrix[newi][newj] == BLOCK){
      ans = max(ans,v);
      continue;
    }
    int step = 0;
    while(matrix[newi][newj] == EMPTY){
      matrix[newi][newj] = FOOTP;
      step++;
      newi+=di;
      newj+=dj;
    }

    if(matrix[newi][newj] == FOOTP){
      ans = max(ans,v+step);
    }else{ // BLOCK
      dfs(newi-di,newj-dj,v+step);
    }

    newi = pi+di;
    newj = pj+dj;
    rep(i,0,step){
      matrix[newi][newj] = EMPTY;
      newi+=di;
      newj+=dj;
    }
  }
}

int main(){
  usefile();
  cin>>n>>b;
  rep(i,0,n+2){
    matrix[0][i] = BLOCK;
    matrix[i][0] = BLOCK;
    matrix[n+1][i] = BLOCK;
    matrix[i][n+1] = BLOCK;
  }
  while(b--){
    char xy[10];
    scanf("%s",xy);
    int y = 0;
    rep(i,1,5){
      if(xy[i] == '\0')break;
      y*=10;
      y+=xy[i]-'0';
    }
    matrix[xy[0]-'A'+1][y] = BLOCK;
  }
  matrix[1][1] = FOOTP;
  dfs(1,1,1);
  cout<<ans<<endl;

  return 0;
}
