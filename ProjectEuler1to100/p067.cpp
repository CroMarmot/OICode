/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期二 2月 25, 2020 12:29:13 CST
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


int n=100;
ll t[110][110];

int main(){
  rep(i,0,n){
    rep(j,0,i+1){
      scanf("%lld",&t[i][j]);
    }
  }
  per(i,0,n){
    rep(j,0,i+1){
      t[i][j]+=max(t[i+1][j],t[i+1][j+1]);
    }
  }
  cout<<t[0][0]<<endl;
  return 0;
}

// time cat p067_triangle.txt  | ./p067
