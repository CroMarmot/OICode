/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期四 6月 18, 2020 18:09:10 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

const int N = 1'000'000;

vector<pair<int,int> > v2p[N+10];

int p[N+10];
int nex[N+10];
int cir[N+10];


int dfs(ll v, map<int,int> & p2d,int dep = 0){
  // printf("dfs:%lld,%d\n",v,dep);
  if(v >= N){
    return 0;
  }
  if(p2d.count(v)){
    cir[v] = dep - p2d[v];
    return v;
  }
  p2d[v] = dep;
  if(cir[v] != 0) return v;
  int r = dfs(nex[v],p2d,dep+1);
  if(p2d[r] > dep) {
    cir[v] = -1;
  }else if(p2d[r] < dep){
    cir[v] = cir[r];
  }
  return r;
}

int main(){
  rep(i,2,N+1){
    if(p[i]){
      continue;
    }
    nex[i] = 1;
    for(ll j = i*i;j<=N ;j+=i){
      p[j] = i;
    }
  }
  rep(i,2,N+1){
    if(!p[i])continue;
    ll r = 1;
    ll ii = i;
    while(ii!=1){
      ll p1 = p[ii];
      if(p1 == 0){
        p1 = ii;
      }
      ll m = 1;
      while(ii%p1 == 0){
        m *= p1;
        ii/=p1;
      }
      r *= (m*p1-1)/(p1-1);
    }
    nex[i] = r - i;
  }
  cir[0] = -1;

  rep(i,1,N+1){
    if(cir[i])continue;
    map<int,int> m;
    dfs(i,m);
  }
  int maxd = 0;
  rep(i,1,N+1){
    if(cir[i] > maxd){
      maxd = cir[i];
      printf("%lld->%d [%d]\n",i,nex[i],cir[i]);
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

