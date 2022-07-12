/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期五 2月 07, 2020 16:38:17 CST
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

const int PN = 100'000'000;

int p[PN+10];
const int N = 5; // change this to 4
int vals[10];
int trys;


// 要利用低维度数组的信息

map<int,bool>vis[10];
map<int,vector<vector<int> > > sumof[10];

int t(int v){
  int r = 1;
  while(v){
    r*=10;
    v/=10;
  }
  return r;
}

bool notPrime(ll v){
  if(v <= PN){
    return p[v];
  }
  for(ll ii = 2;ii*ii <= v;ii++){
    if(v%ii==0)return true;
  }
  return false;
}

bool concat(int v1,int v2){
  trys++;
  return !notPrime(v1*t(v2)+v2) && !notPrime(v2*t(v1)+v1);
}

vector<vector<int> > f(int cnt,int sum){
  if(vis[cnt][sum]){
    return sumof[cnt][sum];
  }
  vis[cnt][sum] = true;
  if(cnt == 2){
    rep(i,3,sum){
      if(i>=sum-i)break;
      if(notPrime(i))continue;
      if(notPrime(sum-i))continue;
      if(concat(i,sum-i)){
        sumof[cnt][sum].pb({i,sum-i});
      }
    }
    return sumof[cnt][sum];
  }
  // cnt > 2
  // low... i
  rep(i,max(3,sum/cnt),sum){
    if(notPrime(i))continue;
    vector<vector<int> > vlow = f(cnt-1,sum-i);
    for(auto item:vlow){
      if(i <= item[cnt-2]){
        continue;
      }
      bool ok = true;
      rep(j,0,cnt-1){
        if(!concat(item[j],i)){
          ok = false;
          break;
        }
      }
      if(ok){
        vector<int> v;
        rep(j,0,cnt-1){
          v.pb(item[j]);
        }
        v.pb(i);
        sumof[cnt][sum].pb(v);
      }
    }
  }
  return sumof[cnt][sum];
}

int main(){
  rep(i,2,10'000){
    if(p[i])continue;
    for(ll j = i*i;j<=PN;j+=i){
      p[j]=true;
    }
  }
  for(int s=N*3;;s++){
    if((s-N)%2!=0)continue; // 奇偶性在这里保证
    trys = 0;
    auto ret = f(N,s);
    if(ret.size() > 0 ){
      for(auto item:ret){
        for(auto itema:item){
          cout<<itema<<endl;
        }
        cout<<s<<endl;
        cout<<"--------"<<endl;
      }
      return 0;
    }
    cout<<s<<":"<<trys<<endl;
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

