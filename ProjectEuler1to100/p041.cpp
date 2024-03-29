/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期一 2月 03, 2020 14:56:09 CST
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

bool checkp(int v){
  // cout<<v<<endl;
  rep(i,2,32000){
    if(i>=v)return true;
    if(v%i == 0)return false;
  }
  return true;
}

int d[10];
int vis[10];

bool dfs(int idx,int l){
  if(idx == l){
    int v = 0;
    rep(i,0,l){
      v*=10;
      v+=d[i];
    }
    int r = checkp(v);
    if(r){
      printf("%d\n",v);
    }
    return r;
  }
  per(i,1,l+1){
    if(vis[i])continue;
    vis[i]=true;
    d[idx]=i;
    bool r = dfs(idx+1,l);
    if(r)return true;
    vis[i]=false;
  }
  return false;
}


int main(){
  per(i,1,10){
    if(dfs(0,i)){
      return 0;
    }
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

