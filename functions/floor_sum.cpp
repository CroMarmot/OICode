#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// \sum_{x=0}^n \lfloor \frac{ax+b}{c} \rfloor
ll floor_sum(ll a,ll b,ll c,ll n){
  if(a==0) return (b/c)*(n+1);
  if(a >= c or b >= c) return n*(n+1)/2*(a/c) + (n+1)*(b/c) + floor_sum(a%c,b%c,c,n);
  ll m = (a*n+b)/c;
  return m*n - floor_sum(c,c-b-1,a,m-1);
}

int main(){
  assert(floor_sum(5,6,7,8) == 29);
  return 0;
}


