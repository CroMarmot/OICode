/*
ID: 10157591
PROG: milk4
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "milk4";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int vis[20010];
int ans[110];
int val[20010];
int Q;
int P;
int dep;

bool check(){
  rep(i,1,Q+1){
    vis[i]=0;
  }
  rep(i,0,dep){
    rep(j,0,Q+1-ans[i]){
      if(vis[j]){
        vis[j+ans[i]]=true;
      }
    }
  }
  if(vis[Q]){
    return true;
  }
  return false;
}

bool dfs(int idx,int cnt){
  ans[cnt] = val[idx];
  if(cnt+1 == dep){
    return check();
  }
  rep(j,idx+1,P+2+cnt-dep){
    if(dfs(j,cnt+1)){
      return true;
    }
  }
  return false;
}

void output(){
  printf("%d",dep);
  rep(i,0,dep){
    printf(" %d",ans[i]);
  }
  printf("\n");
}

int main(){
  usefile();
  cin>>Q;
  cin>>P;
  rep(i,0,P){
    scanf("%d",val+i);
  }
  sort(val,val+P);
  vis[0]=1;
  for(dep=1;dep<=P;dep++){
    rep(i,0,P+1-dep){
      if(dfs(i,0)){
        output();
        return 0;
      }
    }
  }
  return 0;
}
