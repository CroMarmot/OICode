#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
#define rep(i,a,n) for (ll i=a;i<(ll)n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
template<class T>using minPQ=priority_queue<T,vector<T>,greater<T>>;

ll read(){ll r;scanf("%lld",&r);return r;}
ll modpow(ll v,ll mi){ll r = 1;while(mi){if(mi%2)(r*=v)%=MOD;(v*=v)%=MOD;mi>>=1;};return r;}

vector<vector<ll> > coef;

const int N=70;

ll fac[N+1]={1};
ll ifac[N+1];
ll binom(ll n,ll m){
  assert(n<=N);
  if(m>n or m<0) return 0;
  return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}

// 计算 0^m+1^m+...+x^m = a_i x^i, i=0..m+1 的 a_i系数, mod MOD(is prime)
vector<vector<ll> > calc_power_sum_coef(int mxpwr){
  rep(i,1,mxpwr+1) fac[i]=fac[i-1]*i%MOD;
  ifac[mxpwr] = modpow(fac[mxpwr],MOD-2);
  per(i,0,mxpwr) ifac[i]=ifac[i+1]*(i+1)%MOD;
  vector<vector<ll> > ret;
  ret.push_back({1,1}); // sum 0^0+1^0+2^0+...+x^0 = 1*x^0 + 1*x^1, 这里 认为0^0 = 1方便一致性计算
  rep(m,1,mxpwr) {
    vector<ll> row = vector<ll>(m+2,0); // [0...m+1]次
    // = 1/(m+1)  ((x+1)^(m+1) - sum i=2..m+1 binom(m+1,i) f[m+1-i](x) )
    rep(i,0,m+1+1) (row[i] += binom(m+1,i))%=MOD;
    rep(i,2,m+1+1) {
      ll binom_m_i=binom(m+1,i);
      rep(j,0,m+1-i+1+1) {
        assert(m+1-i < m);
        (row[j] += MOD-binom_m_i*ret[m+1-i][j]%MOD)%=MOD;
      }
    }
    ll inv_m_add_1 = modpow(m+1,MOD-2);
    for(auto &v:row) (v*=inv_m_add_1)%=MOD;
    ret.push_back(row);
  }
  return ret;
}

int main(){
  // https://www.luogu.com.cn/record/159379888
  coef = calc_power_sum_coef(64);
  return 0;
}


