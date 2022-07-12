/*
ID: 10157591
PROG: schlnet
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "schlnet";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;

vector<int>p2[110];

const int N=100;


int id = 0;
bool vis[N+10];
int low[N+10];
int dfn[N+10];
vector<int>stk;
bool instk[N+10];

int incnt[N+10];
int outcnt[N+10];

void scc(int idx){
  // cout<<"scc"<<idx<<endl;
  dfn[idx] = low[idx] = ++id;
  vis[idx] = true;
  stk.push_back(idx);
  instk[idx] = true;
  for(auto item:p2[idx]){
    if(!vis[item]){
      scc(item);
      low[idx]=min(low[idx],low[item]);
    }else if(instk[item]){
      low[idx]=min(low[idx],dfn[item]); // dfn->low
    }
  }
  if(low[idx] == dfn[idx]){
    // cout<<"zip:"<<idx<<endl;
    // for(auto item:stk){
    //   printf("\t\tstk[%d]\n",item);
    // }
    int u;
    do{
      u = *(stk.end()-1);
      // cout<<"\tu:"<<u<<endl;
      dfn[u] = idx;
      instk[u] = false;
      stk.pop_back();
    }while(u != idx);
  }
}

void tarjan(){
  rep(i,1,n+1){
    if(!vis[i]){
      scc(i);
    }
  }
  // rep(i,1,n+1){
  //   cout<<"dfn:"<<i<<" = "<<dfn[i]<<endl;
  // }
}

int main(){
  usefile();
  cin>>n;
  rep(i,1,n+1){
    while(1){
      int v;
      scanf("%d",&v);
      if(v == 0)break;
      p2[i].push_back(v);
    }
  }
  tarjan();
  rep(i,1,n+1){
    if(dfn[i]!=i){
      for(auto item:p2[i]){
        p2[dfn[i]].push_back(dfn[item]);
      }
    }else{
      for(auto &item:p2[i]){
        item = dfn[item];
      }
    }
  }
  rep(i,1,n+1){
    if(dfn[i] == i){
      sort(p2[i].begin(),p2[i].end());
      p2[i].erase(unique(p2[i].begin(),p2[i].end()),p2[i].end());
      for(auto item:p2[i]){
        if(item == i)continue;
        // printf("%d -> %d\n",i,item);
        incnt[item]++;
        outcnt[i]++;
      }
    }
  }
  int in0cnt=0,out0cnt=0;
  rep(i,1,n+1){
    if(dfn[i] == i){
      in0cnt+=incnt[i] == 0;
      out0cnt+=outcnt[i] == 0;
    }
  }
  printf("%d\n",in0cnt);
  // single check
  int pcnt = 0;
  rep(i,1,n+1){
    pcnt+=dfn[i]==i;
  }
  if(pcnt == 1){
    printf("0\n");
  }else{
    printf("%d\n",max(in0cnt,out0cnt));
  }
  return 0;
}
