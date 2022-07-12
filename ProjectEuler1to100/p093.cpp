/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期四 6月 18, 2020 16:04:55 CST
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

const int N = 10000;
bool vis[N+10];

int ansn = 0;
int ans[10];
int val[10];

int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}

pair<int,int> fmtfs(pair<int,int> fs){
  if(fs.first == 0)return {0,1};
  if(fs.second < 0){
    fs.first = -fs.first;
    fs.second = -fs.second;
  }
  int c = gcd(abs(fs.first),fs.second);
  return {fs.first/c,fs.second/c};
}

pair<int,int> operator + (const pair<int,int> & v1, const pair<int,int>&v2){
  return fmtfs({
      v1.first * v2.second + v1.second*v2.first,
      v1.second * v2.second
  });
}

pair<int,int> operator - (const pair<int,int> & v1, const pair<int,int>&v2){
  return fmtfs({
   v1.first * v2.second - v1.second*v2.first,
   v1.second * v2.second
      });
}

pair<int,int> operator * (const pair<int,int> & v1, const pair<int,int>&v2){
  return fmtfs({
  v1.first * v2.first,
  v1.second * v2.second
      });
}

pair<int,int> operator / (const pair<int,int> & v1, const pair<int,int>&v2){
  return fmtfs({
   v1.first * v2.second,
   v1.second * v2.first
      });
}

void reduce(const vector<pair<int,int> > arr){
  if(arr.size() == 1){
    if(arr[0].second == 1 && arr[0].first > 0){
      vis[arr[0].first] = true;
    }
    return ;
  }
  rep(i,0,arr.size()){
    rep(j,i+1,arr.size()){
      vector<pair<int,int> >next;
      rep(k,0,arr.size()){
        if(k == i)continue;
        if(k == j)continue;
        next.pb(arr[k]);
      }
      next.pb(arr[i]+arr[j]);reduce(next);next.pop_back();
      next.pb(arr[i]-arr[j]);reduce(next);next.pop_back();
      next.pb(arr[j]-arr[i]);reduce(next);next.pop_back();
      next.pb(arr[i]*arr[j]);reduce(next);next.pop_back();

      if(arr[j].first != 0){
        next.pb(arr[i]/arr[j]);reduce(next);next.pop_back();
      }
      if(arr[i].first != 0){
        next.pb(arr[j]/arr[i]);reduce(next);next.pop_back();
      }
    }
  }
}

void check(){
  rep(i,1,N) {
    vis[i] = false;
  }

  reduce({
      {val[0],1},
      {val[1],1},
      {val[2],1},
      {val[3],1}
      });

  rep(i,1,N){
    if(!vis[i]){
      if(ansn < i){
        ansn = i;
        rep(j,0,4){
          ans[j] = val[j];
        }
      }
      return ;
    }
  }
}

void d(int idx = 0,int v = 0){
  if(idx == 4){
    check();
    return ;
  }
  rep(i,v,10){
    val[idx] = i;
    d(idx+1,i+1);
  }
}


int main(){
  d();
  rep(i,0,4){
    printf("%d ",ans[i]);
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

