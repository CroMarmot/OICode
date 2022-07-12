/*
ID: 10157591
PROG: milk6
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

string filename = "milk6";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

const int inf = 2'000'000;

int n;
int m;

struct edge{
  int i;
  int f;
  int t;
  int w;
};

int e[40][40];
int e2[40][40];
edge trucksori[1010];
edge trucks[1010];

bool vis[40];
int bfsarr[40];
int pos[1010];
bool bfs(){
  memset(vis,0,sizeof(vis));
  int st = 0,rear = 0;
  vis[bfsarr[rear++]=1]= true;
  while(st < rear){
    int v = bfsarr[st];
    rep(i,1,n+1){
      if(v==n)continue;
      if(vis[i])continue;
      if(!e[v][i])continue;
      vis[bfsarr[rear++] = i] = true;
      if(i == n)return true;
    }
    st++;
  }
  return vis[n];
}

int dfs(int vertex,int val){
  if(vertex == n)return val;
  vis[vertex] = true;
  rep(i,1,n+1){
    if(vis[i])continue;
    if(!e[vertex][i])continue;
    int ret = dfs(i,min(val,e[vertex][i]));
    if(ret){
      e[vertex][i] -= ret;
      e[i][vertex] += ret;
      return ret;
    }
  }
  return 0;
}

int maxFlow(){
  int ret = 0;
  while(bfs()){
    memset(vis,0,sizeof(vis));
    ret += dfs(1,inf);
  }
  return ret;
}

void trucks2e(){
  memset(e,0,sizeof(e));
  rep(i,0,m)
    e[trucks[i].f][trucks[i].t] +=trucks[i].w;
}
void que2(){
  memset(e2,0,sizeof(e2));
  rep(i,0,m){
    e2[trucks[i].f][trucks[i].t] +=trucks[i].w;
  }
  rep(i,1,n+1){
    rep(j,1,n+1){
      e2[i][j] = (!e[i][j] && e2[i][j])?-1:e2[i][j]; // 标记哪两点之间的 流被耗尽
    }
  }
  rep(i,0,m){
    if(e2[trucks[i].f][trucks[i].t] == -1){//把耗尽的流所包含的边记为1
      trucks[i].w = 1;
    }else
      trucks[i].w = inf; //把残余边改为inf
  }
  trucks2e();
}
int asz = 0;
int ans[1010];

int main(){
  usefile();
  cin>>n>>m;
  int idx = 0;
  rep(i,0,m){
    scanf("%d %d %d",&trucks[idx].f,&trucks[idx].t,&trucks[idx].w);
    trucks[idx].i = i+1;
    trucksori[idx] = trucks[idx];// 备份
    if(trucks[idx].w) // remove w==0
      idx++;
  }
  m = idx;
  trucks2e();
  int flow ;
  // 找最大流/最小割
  printf("%d ",flow = maxFlow());
  // 让最小割数量最小:把上一步处理后 所有0置位1,所有非零置为inf,再求一遍最大流
  que2();
  int T;
  printf("%d\n",T = maxFlow());
  // 在上一次基础上 采取标记可能性
  rep(i,0,m){ // 32*32 约等于 1000
    if(trucks[i].w!=1)continue;
    trucks[i].w = 0;
    trucks2e();
    int mf = maxFlow();
    if(mf < T){
      pos[i] = true;
    }
    trucks[i].w = 1;
  }
  // 在原来的图上尝试删边
  rep(i,0,m)
    trucks[i] = trucksori[i];

  rep(i,0,m){ // 32*32 约等于 1000
    if(!pos[i])continue;
    int w = trucks[i].w;
    trucks[i].w = 0;
    trucks2e();
    int mf = maxFlow();
    if(mf+w == flow){
      printf("%d\n",trucks[i].i);
      flow -= w;
      continue;
    }
    trucks[i].w = w;
  }
  return 0;
}
