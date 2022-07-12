/*
ID: 10157591
PROG: vans
LANG: C++
*/
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back


using namespace std;

const string filename = "vans";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

class hpa{
  int DIGITS = 100'000'000; // 08lld
  vector<ll>vals;
public:
  hpa(){
  }
  hpa(ll v){
    vals.pb(v);
  }
  void print(){
    if(vals.size() == 0){
      printf("0");
      return;
    }
    printf("%lld",vals[vals.size()-1]);
    per(i,0,vals.size()-1){
      printf("%08lld",vals[i]);
    }
  }
  hpa operator +(const hpa &another) const {
    hpa ret;
    rep(i,0,vals.size()){
      ret.vals.pb(vals[i]);
    }
    rep(i,0,another.vals.size()){
      if(i >= ret.vals.size()){
        ret.vals.pb(another.vals[i]);
      }else{
        ret.vals[i]+=another.vals[i];
        if(ret.vals[i] >= DIGITS){
          if(i == ret.vals.size()-1){
            ret.vals.pb(0);
          }
          ret.vals[i+1]+=ret.vals[i]/DIGITS;
          ret.vals[i]%=DIGITS;
        }
      }
    }
    return ret;
  }
};

int n;

const int S1001 = 0;
const int S1122 = 1;
const int S1100 = 2;
const int S0110 = 3;
const int S0011 = 4;
const int S1221 = 5;
const int S0000 = 6;

hpa dp[1010][10];
int s2[10][10];

void init(){
  s2[S1001][S0000] = 1;
  s2[S1001][S1100] = 1;
  s2[S1001][S0110] = 1;
  s2[S1001][S0011] = 1;
  s2[S1001][S1221] = 1;

  s2[S1122][S1001] = 1;
  s2[S1122][S1122] = 1;
  // s2[S1122][S1100] = 1; 不应该自闭
  // s2[S1122][S0011] = 1; 不应该自闭
  // s2[S1122][S0000] = 1; 不应该自闭

  s2[S1100][S1122] = 1;
  s2[S1100][S1001] = 1;

  s2[S0110][S1001] = 1;

  s2[S0011][S1122] = 1;
  s2[S0011][S1001] = 1;

  // s2[S1221][S1001] = 1; 不应该自闭
  s2[S1221][S0000] = 1;
  s2[S1221][S1100] = 1;
  s2[S1221][S0011] = 1;
  s2[S1221][S1221] = 1;
}

int main(){
  usefile();
  init();
  cin>>n;

  dp[0][S1001] = 2;
  dp[0][S1122] = 2;
  rep(i,1,n){
    rep(stateS,0,6){
      rep(stateE,0,7){
        if(s2[stateS][stateE]){
          dp[i][stateE]=(dp[i][stateE]+dp[i-1][stateS]);
        }
      }
    }
  }
  // rep(i,0,n){
  //   rep(state,0,7){
  //     cout<<dp[i][state]<<"\t";
  //   }
  //   cout<<endl;
  // }
  dp[n-1][S0000].print();
  printf("\n");
  return 0;
}
