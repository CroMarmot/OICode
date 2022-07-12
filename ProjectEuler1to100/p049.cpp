/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期二 2月 04, 2020 09:02:01 CST
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

int p[10010];

int o(int v){
  int arr[] = {v%10,(v/10)%10,(v/100)%10,(v/1000)%10};
  sort(arr,arr+4);
  return arr[0]*1000+arr[1]*100+arr[2]*10+arr[3];
}


int main(){
  rep(i,2,101){
    if(p[i])continue;
    for(int j = i*i;j<=10000;j+=i){
      p[j]=true;
    }
  }
  rep(i,1000,10000){
    if(p[i])continue;
    int oi = o(i);
    if(oi == -1)continue;
    rep(j,2,4501){
      if(i+2*j<10000 && !p[i+j] && !p[i+2*j]){
        if(oi == o(i+j) && oi == o(i+2*j)){
          printf("%d %d %d\n",i,i+j,i+2*j);
        }
      }
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

