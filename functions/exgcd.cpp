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

// 返回的 [x,y,z] 满足 a*x+b*y=z=gcd(a,b)
tuple<int,int,int> exgcd(int a,int b){
  if(b==0)
    return make_tuple(1,0,a);
  auto [x,y,z] = exgcd(b,a%b);
  return  {y,x-(a/b)*y,z};
}

int main(){
  auto [x,y,z] = exgcd(31,7);
  cout<<x<<endl;
  cout<<y<<endl;
  cout<<z<<endl;
  return 0;
}

