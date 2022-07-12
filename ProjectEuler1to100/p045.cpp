/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期一 2月 03, 2020 18:16:13 CST
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


ll t(ll n){
  return n*(n+1)/2;
}

ll p(ll n){
  return n*(3*n-1)/2;
}

ll h(ll n){
  return n*(2*n-1);
}

int main(){
  int tt = 1;//286;
  int pp = 1;//66;
  int hh = 1;//44;
  ll tr = t(tt);
  ll pr = p(pp);
  ll hr = h(hh);
  while(true){
    if(tr == pr && tr == hr){
      cout<<tr<<endl;
    }
    if(tr <= pr && tr <= hr){
      tt++;
      tr=t(tt);
    }else if(pr <= tr && pr<= hr){
      pp++;
      pr=p(pp);
    }else{
      hh++;
      hr=h(hh);
    }
  }

  return 0;
}
