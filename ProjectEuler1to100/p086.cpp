/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期六 6月 13, 2020 19:15:16 CST
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


ll ans[100000] ;

ll f(int N){
  if(ans[N] != 0)return ans[N];
  if(N == 1)return 0;
  ans[N] = f(N-1);
  rep(i,1,N+1){
    rep(j,i,N+1){
      ll root = (i+j)*(i+j)+N*N;
      ll v = sqrt(root);
      if( v*v == root){
        ans[N]++;
      }
    }
  }
  return ans[N];
}

int main(){
  assert(f(100) == 2060);
  assert(f(99) == 1975);
  ll v = 100;
  while(true){
    if(f(v) > 1'000'000){
      printf("%lld\n",v);
      return 0;
    }
    v++;
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

