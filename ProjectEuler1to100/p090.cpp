/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期四 6月 18, 2020 10:22:57 CST
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


int val[2][10];
int ans = 0;

bool check(){
  rep(i,0,2){
    val[i][6] = -1;
    rep(j,0,6){
      if(val[i][j] == 6 || val[i][j] == 9){
        val[i][6] = 15-val[i][j];
        break;
      }
    }
  }
  rep(i,1,10){
    int a = (i*i)/10;
    int b = (i*i)%10;
    bool ain[2] = {false,false};
    bool bin[2] = {false,false};
    rep(i,0,2){
      rep(j,0,7){
        if(a == val[i][j]){
          ain[i] = true;
        }
        if(b == val[i][j]){
          bin[i] = true;
        }
      }
    }
    if(ain[0] && bin[1])continue;
    if(ain[1] && bin[0])continue;
    return false;
  }
  ll v[2] = {0,0};
  rep(i,0,2){
    rep(j,0,6){
      v[i]*=10;
      v[i]+=val[i][j];
    }
  }
  if(v[1] >= v[0]){
    return true;
  }else{
    return false;
  }
  printf("\n");
  return true;
}

void dfs2(int idx = 0,int cnt = 0){
  if(cnt == 6){
    ans += check();
    return ;
  }
  rep(j,idx,10){
    val[1][cnt] = j;
    dfs2(j+1,cnt+1);
  }
}

void dfs1(int idx = 0,int cnt = 0){
  if(cnt == 6){
    dfs2();
    return ;
  }
  rep(j,idx,10){
    val[0][cnt] = j;
    dfs1(j+1,cnt+1);
  }
}


int main(){
  dfs1();
  printf("%d\n",ans);

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

