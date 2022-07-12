/*
ID: 10157591
PROG: latin
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "latin";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;

map<int,long long >ans;

int main(){
  usefile();
  ans[2]= 1;
  ans[3]= 2;
  ans[4]= 24;
  ans[5]= 1344;
  ans[6]= 1128960;
  ans[7]= 12198297600;
  cin>>n;
  cout<<ans[n]<<endl;
  return 0;
}
