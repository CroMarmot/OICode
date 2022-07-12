/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期日 6月 14, 2020 20:08:21 CST
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

// k = 2 -> 4
// k = 7 => 1x1x1x1x1xaxb = 5+a+b -> (a-1)(b-1) = 6 -> ((2+1)*(3+1)=12,(1+1)*(6+1) = 14)
// 1x1x1x2x2x2x2 = 4+6

// 111ab -> 3+a+b=ab -> 4 = (a-1)(b-1)

// 5+a+b = ab
// 4+a+b+c = abc
//
// 7 => 12
// 6+a+b = ab
// product_{a_i} = sum{a_i}+nof1


const int N = 12000;
ll k[N+10];
// <= 24000

void dfs(ll cnt,ll stv,ll mul,ll sum){
  if(cnt > N)return ;

  ll der = mul-sum;
  if(der>=0 && der+cnt <= N && der+cnt>=2){
    if(k[der+cnt] == 0 || k[der+cnt] > mul){
      k[der+cnt] = mul;
    }
  }
  int i = stv;
  while(mul*i - (sum+i) + cnt+1 <= N && i <= 2*N){
    dfs(cnt+1,i,mul*i,sum+i);
    i++;
  }
}

int main(){
  dfs(0,2,1,0);
  set<int>ans;
  rep(i,2,N+1){
    ans.insert(k[i]);
    printf("%d %lld\n",i,k[i]);
  }
  ll output = 0;
  for(auto item:ans){
    output+=item;
  }
  printf("%lld\n",output);

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

