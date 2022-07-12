/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期一 2月 03, 2020 08:55:56 CST
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

char s[30];

int cnt[30];
// 数位dp

void calc(int idx,int count,vector<int> digits){
  int c = cnt[8-idx];
  vector<int>next ;
  if(idx==9){
    s[idx] = digits[0]+'0';
   return;
  }
  s[idx] = digits[count/c]+'0';
  rep(i,0,digits.size()){
    if(i == count/c)continue;
    next.pb(digits[i]);
  }
  calc(idx+1,count%c,next);
}

int main(){
  cnt[0] = 1;
  rep(i,1,10){
    cnt[i]=cnt[i-1]*(i+1);
  }
  int n;
  // cin>>n;
  n = 1'000'000;
  calc(0,n - 1,{0,1,2,3,4,5,6,7,8,9});
  printf("%s",s);
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

