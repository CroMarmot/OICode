/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期五 2月 07, 2020 20:17:15 CST
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

const int MAXZS = 100'000'000;
int p[MAXZS+10];
int zsidx;
int zs[MAXZS];

int v[10];
const int BAR = 27000;
const int N = 5;
int curans = BAR*N;

int pt;
int ptable;
bool isprime(ll v){
  pt++;
  if(v <= MAXZS ){
    ptable++;
    return !p[v];
  }
  rep(i,0,zsidx){
    if(v%zs[i]==0)return false;
  }
  for(ll i = zs[zsidx-1]+2;i*i<=v;i++){
    if(v%i==0)return false;
  }
  return true;
}

// fail return true
bool check(ll v1,ll v2){
  ll t = 1;
  while(t <= v1){
    t*=10;
  }
  ll v = v1+v2*t;
  if(!isprime(v))return true;
  t = 1;
  while(t <= v2){
    t*=10;
  }
  v = v2+v1*t;
  return !isprime(v);
}

bool dfs(int idx){
  if(idx == N){
    int s =0;
    rep(i,0,N){
      s+=zs[v[i]];
      cout<<zs[v[i]]<<endl;
    }
    cout<<"-----"<<endl;
    curans=min(curans,s);
    return true;
  }
  if(idx == 0){
    rep(i,0,zsidx){
      if(zs[i] * N >= curans)return false;
      v[idx] = i;
      dfs(idx+1);
    }
  }else{
    ll leftv = curans;
    rep(i,0,idx){
      leftv -= zs[v[i]];
    }
    rep(i,v[idx-1]+1,zsidx){
      if(zs[i] * (N-idx) >= leftv) break;
      bool chk = true;
      // check
      rep(j,0,idx){
        if(check(zs[i],zs[v[j]])){
          chk = false;
          break;
        }
      }
      if(!chk)continue;
      v[idx] = i;
      dfs(idx+1);
    }
  }
  return false;
}


int main(){
  rep(i,2,10'000){
    if(p[i])continue;
    for(ll j = i*i;j<=MAXZS;j+=i){
      p[j]=true;
    }
  }
  cout<<"init prime"<<endl;
  rep(i,3,BAR){
    if(p[i])continue;
    zs[zsidx++]=i;
  }
  cout<<zsidx<<endl;
  dfs(0);
  cout<<"ptable/pt:"<<ptable<<"/"<<pt<<endl;
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

