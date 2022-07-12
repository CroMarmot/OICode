/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期六 6月 13, 2020 19:27:43 CST
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

const int N = 50'000'000;
const int PN = 8000;
int p[PN];
int stki = 0;
int pr[PN];

int main(){
  rep(i,2,PN){
    if(pr[i])continue;
    p[stki++]= i ;
    for(int j = i*i;j<PN;j+=i){
      pr[j] = 1;
    }
  }
  set<ll>ans;
  rep(i,0,stki){
    ll i2 = p[i]*p[i];
    if(i2 >= N)break;
    rep(j,0,stki){
      ll i2j3 = i2+p[j]*p[j]*p[j];
      if(i2j3 >= N)break;
      rep(k,0,stki){
        ll i2j3k4 = i2j3+p[k]*p[k]*p[k]*p[k];
        if(i2j3k4 >= N)break;
        ans.insert(i2j3k4);
      }
    }
  }
  for(auto item:ans){
    printf("%d\n",item);
  }
  printf("%d",ans.size());
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

