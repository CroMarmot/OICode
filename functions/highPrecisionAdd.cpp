/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期二 6月 25, 2019 14:45:56 CST
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
    hpa ret ;
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

int main(){
  hpa a(100000);
  hpa b(10'000'000);
  rep(i,0,100){
    a=(a+b);
    a.print();
    cout<<endl;
  }
  return 0;
}
