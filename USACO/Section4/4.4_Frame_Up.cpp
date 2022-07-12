/*
ID: 10157591
PROG: frameup
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

string filename = "frameup";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

#define IMIN 0
#define IMAX 1
#define JMIN 2
#define JMAX 3

const int inf = 50;

char s[40][40];
int BOUND[4][30];

int h,w;

int child[30][30];
int chcnt[30];
int vis[30];

int getv(char ch){
  return ch-'A';
}

void addchild(int vdown,int vup){
  if(child[vdown][vup] == 0){
    child[vdown][vup] = 1;
    chcnt[vup]++;
  }
}
int maxv = 0;

vector<string>ans;

char anstmp[30];

int subchild[30][30];
int exist[30];

void dfs(int dep){
  rep(v,0,26){
    if(!exist[v])continue;
    if(vis[v])continue;
    if(chcnt[v] == 0){
      vis[v] = true;
      anstmp[dep] = v+'A';
      rep(v2,0,26){
        if(!exist[v2])continue;
        if(child[v][v2] == 1){
          child[v][v2] = 0;
          subchild[v][v2] = 1;
          chcnt[v2] --;
        }
      }
      if(dep == maxv-1)
        ans.push_back(anstmp);
      else
        dfs(dep+1);
      rep(v2,0,26){
        if(!exist[v2])continue;
        if(subchild[v][v2] == 1){
          subchild[v][v2] = 0;
          child[v][v2] = 1;
          chcnt[v2] ++;
        }
      }
      vis[v] = false;
    }
  }
}

int main(){
  usefile();
  cin>>h>>w;
  rep(i,0,h){
    scanf("%s",s[i]);
  }

  rep(i,0,26){
    BOUND[IMIN][i] = inf;
    BOUND[JMIN][i] = inf;
    BOUND[IMAX][i] = -inf;
    BOUND[JMAX][i] = -inf;
  }

  rep(i,0,h){
    rep(j,0,w){
      if(s[i][j] == '.')continue;
      int v = getv(s[i][j]);
      if(!exist[v]){
        exist[v] = true;
        maxv++;
      }
      BOUND[IMIN][v] = min(BOUND[IMIN][v],i);
      BOUND[IMAX][v] = max(BOUND[IMAX][v],i);
      BOUND[JMIN][v] = min(BOUND[JMIN][v],j);
      BOUND[JMAX][v] = max(BOUND[JMAX][v],j);
    }
  }
  rep(v,0,26){
    if(!exist[v])continue;
    rep(i,BOUND[IMIN][v],BOUND[IMAX][v]+1){
      if(getv(s[i][BOUND[JMIN][v]]) != v)addchild(v,getv(s[i][BOUND[JMIN][v]]));
      if(getv(s[i][BOUND[JMAX][v]]) != v)addchild(v,getv(s[i][BOUND[JMAX][v]]));
    }
    rep(j,BOUND[JMIN][v],BOUND[JMAX][v]+1){
      if(getv(s[BOUND[IMIN][v]][j]) != v)addchild(v,getv(s[BOUND[IMIN][v]][j]));
      if(getv(s[BOUND[IMAX][v]][j]) != v)addchild(v,getv(s[BOUND[IMAX][v]][j]));
    }
  }
  dfs(0);
  sort(ans.begin(),ans.end());
  for(auto item:ans){
    printf("%s\n",item.c_str());
  }

  return 0;
}
