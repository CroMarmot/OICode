/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期一 2月 03, 2020 14:10:53 CST
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

int v;

int main(){
  rep(i,1,100000){
    set<int>s;
    int v = 0;
    bool ok = true;
    rep(j,1,10){
      int m = j*i;
      int t = 1;
      int mm = m;
      while(mm){
        if(mm%10 == 0 || s.count(mm%10)){
          ok = false;
          break;
        }
        s.insert(mm%10);
        mm/=10;
        t*=10;
      }
      v*=t;
      v+=m;
      if(!ok)break;
      if(s.size() == 9 && j > 1){
        printf("%d,1->%d = %d\n",i,j,v);
      }
    }
    if(!ok)continue;
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

