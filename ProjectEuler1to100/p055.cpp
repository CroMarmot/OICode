/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期三 2月 05, 2020 09:14:40 CST
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


int bits[1000];
int rev[1000];

int main(){
  int ans = 0;
  rep(i,10,10'000){
    int l = 0;
    int ii = i;
    while(ii){
      bits[l++]=ii%10;
      ii/=10;
    };
    bool ok = false;
    rep(itr,0,50){
      rep(i,0,l){
        rev[i] = bits[l-i-1];
      }
      bits[l] = 0;
      rep(j,0,l){
        bits[j]+=rev[j];
        bits[j+1]+=bits[j]/10;
        bits[j]%=10;
      }
      if(bits[l]){
        l++;
      }
      ok = true;
      rep(j,0,l){
        if(bits[j] != bits[l-j-1]){
          ok = false;
          break;
        }
      }
      if(ok){
        // cout<<i<<":"<<itr<<endl;
        break;
      }
    }
    if(ok){
      continue;
    }
    ans++;
    cout<<i<<endl;
  }
  cout<<ans<<endl;
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

