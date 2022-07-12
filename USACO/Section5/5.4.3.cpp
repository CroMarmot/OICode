/*
ID: 10157591
PROG: telecow
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "telecow";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n,m,c1,c2;

int p2p[210][210];

int vis[210];
int flow[210][210];

void clearvis(){
  rep(i,1,2*n+1){
    vis[i]=false;
  }
}

void dup(){
  rep(i,1,2*n+1){
    rep(j,1,2*n+1){
      flow[i][j]=p2p[i][j];
    }
  }
}

int stk[210];

int bfs(int idx,int dst){
  clearvis();
  int st = 0,rear=0;
  stk[rear++]=idx;
  vis[idx] = true;
  while(st<rear){
    int p = stk[st];
    rep(i,1,n*2+1){
      if(vis[i])continue;
      if(flow[p][i]){
        if(i == dst){
          return true;
        }
        stk[rear++]=i;
        vis[i]=true;
      }
    }
    st++;
  }
  return false;
}

int dfs(int idx,int dst){
  if(idx == dst){
    return 1;
  }
  vis[idx] = true;
  rep(i,1,2*n+1){
    if(vis[i])continue;
    if(!flow[idx][i])continue;
    int r = dfs(i,dst);
    if(r){
      flow[idx][i] -= r;
      flow[i][idx] += r;
      return r;
    }
  }
  return 0;
}

int maxflow(){
  int ret =0;
  while(bfs(c1*2,c2*2-1)){
    clearvis();
    ret+=dfs(c1*2,c2*2-1);
  }
  return ret;
}

void addp(int p1,int p2){
  int p1i=p1*2-1;
  int p1o=p1*2;
  int p2i=p2*2-1;
  int p2o=p2*2;
  if(p1!=c1 && p2 != c2){
    p2p[p2o][p1i] = 1;
  }
  if(p1!=c2 && p2 != c1){
    p2p[p1o][p2i] = 1;
  }
}

int main(){
  usefile();
  cin>>n>>m>>c1>>c2;
  rep(i,0,m){
    int a,b;
    scanf("%d %d",&a,&b);
    addp(a,b);
  }
  rep(i,1,n+1){
    p2p[i*2-1][i*2]=1;
  }
  dup();
  int ans = maxflow();
  cout<<ans<<endl;
  vector<int>ps;
  rep(i,1,n+1){
    if(i== c1 || i==c2){
      continue;
    }
    dup();
    flow[i*2-1][i*2]=0;
    int ret = maxflow();
    if(ret == ans-1){
      ps.push_back(i);
      ans-=1;
      p2p[i*2-1][i*2]=0;
    }
  }
  rep(i,0,ps.size()){
    printf("%d%c",ps[i]," \n"[i==ps.size()-1]);
  }
  return 0;
}
