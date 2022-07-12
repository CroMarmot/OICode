/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期六 2月 08, 2020 10:27:50 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

// AB
// BC
// CD
// DE
// EF
// FA

int N = 6; // change this

map<int,vector<int> > vals[10]; // [type][front2] = { last2 };

int vis[10];
int cur[10];

bool dfs(int front,int cnt,int st){
  // printf("dfs %d,%d,%d\n",front,cnt,st);
  cur[cnt] = front;
  if(cnt == N-1){
    rep(i,0,N){
      if(vis[i])continue;
      for(auto item:vals[i][front]){
        if(item == st){
          int s = 0;
          rep(i,0,N){
            cout<<cur[i]<<endl;
            s+=cur[i]*100+cur[(i+1)%N];
          }
          cout<<"sum="<<s<<endl;
          cout<<"-------"<<endl;
          return true;
        }
      }
    }
    return false;
  }
  rep(i,0,N){
    if(vis[i])continue;
    vis[i] = true;
    for(auto item:vals[i][front]){
      int r = dfs(item,cnt+1,st);
      if(r)return true;
    }
    vis[i] = false;
  }
  return false;
}

int main(){
  rep(i,0,6){
    rep(j,0,200){
      int v = j*((i+1)*j-(i-1))/2;
      if(v<1000)continue;
      if(v>=10000)break;
      vals[i][v/100].pb(v%100);
    }
  }
  for(auto item:vals[0]){
    int r = dfs(item.first,0,item.first);
    if(r)return 0;
  }
  return 0;
}

/*
 *
 * hash prime
   61,83,113,151,211,281,379,509683,911
   1217,1627,2179,2909,3881,6907,9209
   12281,16381,21841,29123,38833,51787,69061,92083
   122777,163729,218357,291143,388211,517619,690163,999983
   1226959,1635947,2181271,2908361,3877817,5170427,6893911,9191891
   12255871,16341163,21788233,29050993,38734667,51646229,68861641,91815541
   122420729,163227661,217636919,290182597,386910137,515880193,687840301,917120411
   1000000007,1000000009
 * */

