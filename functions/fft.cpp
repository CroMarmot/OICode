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

// n个数 2*10^5
// x正负10的9次方
// 求对所有k=0~n,原数组中 正好有k个小于x的数的数组段 有多少个


int n;
ll x;
ll a[200010];
ll t[400010];
ll r[400010];

vector<complex<double>>t_cp,r_cp,s;
// bit 翻转
int rev(int x, int len) {
  int ans = 0;
  rep(i, 0, len) {
    ans <<= 1;
    ans |= x & 1;
    x >>= 1;
  }
  return ans;
}

int getlog2(int n){
  int ret = 0;
  while(n!=1){
    ret ++;
    n>>=1;
  }
  return ret;
}

void FFT(vector<complex<double> > &A, int flag) {
  int n = A.size();
  int lgn = getlog2(n);
  rep(i, 0, n) {
    int j = rev(i, lgn);
    if (j > i)
      swap(A[i], A[j]);
  }

  for (int m = 1; m < n; m <<= 1) {
    complex<double> Wm(cos(pi / m), -sin(pi / m) * flag);
    for (int k = 0; k < n; k += (m<<1)) {
      complex<double> W(1, 0);
      rep(j, 0, m) {
        complex<double> U = A[k + j], T = W * A[k + j + m];
        A[k + j] = U + T;
        A[k + j + m] = U - T;
        W *= Wm;
      }
    }
  }
}

int main(){
  cin>>n>>x;
  rep(i,0,n)scanf("%lld",a+i);
  int cnt = 0;
  t[cnt]++;
  rep(i,0,n){
    cnt += (a[i]<x);
    t[cnt]++;
  }
  // ans[k] = sum(t[a]*t[a+k])
  rep(i,0,n+1)r[i]=t[n-i];
  // ans[k] = sum(t[a]*r[n-a-k])
  // 卷积 (t*r)[v] = (t*r)[n-k]

  ll ans0 = 0;
  rep(i,0,n+1){
    ans0 += t[i]*(t[i]-1)/2;
  }

  int len = 1;
  while(len < 2*(n+1)){
    len<<=1;
  }
  rep(i,0,n+1)t_cp.pb(t[i]);
  rep(i,n+1,len)t_cp.pb(0);
  rep(i,0,n+1)r_cp.pb(r[i]);
  rep(i,n+1,len)r_cp.pb(0);

  FFT(t_cp,1);
  FFT(r_cp,1);
  rep(i,0,len)s.pb(t_cp[i]*r_cp[i]);
  FFT(s,-1);
  rep(i,0,len)s[i]/=len;
  s[n] = ans0;
  per(i,0,n+1){
    printf("%lld ",(ll)(s[i].real()+0.25));
  }
  return 0;
}
