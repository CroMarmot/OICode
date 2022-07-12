/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期二 2月 04, 2020 10:55:00 CST
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

int p[1'000'001];

int bar = 8;

bool dfs(const vector<int> & m,int idx,int val,int msk,int sti){
  if(idx == m.size()){
    if(msk == 0)return false;
    int zscnt = 0;
    rep(i,sti,10){
      zscnt+=!p[val+(i-sti)*msk];
    }
    if(zscnt >= bar){
      cout<<val<<endl;
      cout<<msk<<endl;
      return true;
    }
    return false;
  }
  int r;
  r=dfs(m,idx+1,val,msk,sti);
  if(r)return r;
  return dfs(m,idx+1,val,msk+m[idx],sti);
}

bool eight(int v){
  int t = 1;
  vector<int>mask[3]; // 0 1 2
  while(v>=t){
    int digit = (v/t)%10;
    if(digit < 3){
      mask[digit].pb(t);
    }
    t*=10;
  }
  rep(i,0,11-bar){
    if(mask[i].size()){
      int r = dfs(mask[i],0,v,0,i);
      if(r) return true;
    }
  }
  return false;
}

int main(){
  rep(i,2,1'001){
    if(p[i])continue;
    for(int j = i*i;j<=1'000'001;j+=i){
      p[j]=1;
    }
  }
  rep(i,2,1'000'001){
    if(p[i])continue;
    if(eight(i))return 0;
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

