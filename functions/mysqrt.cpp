#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mysqrt(ll v){
  if(v == 0)return 0;
  assert(v > 0);
  ll l = 1;
  ll r = v;
  while(l != r){
    ll mid = (l+r)/2;
    // 先控范围防止 overflow
    if( v/mid < mid ){
      r = mid - 1;
    }else if( mid * mid <= v && (mid+1)*(mid+1) > v){
      return mid;
    }else if( (mid+1) * (mid+1) <= v){
      l = mid + 1;
    }else {
      r = mid - 1;
    }
  }
  return l;
}

int main(){
  return 0;
}

