/*
ID: 10157591
PROG: tour
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "tour";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

char s[210],t[210];
map<string,int>str2idx;
int n,m,mp[110][110],dp[110][110];
int main(){
  usefile();
  scanf("%d%d",&n,&m);
  rep(i,0,n){
    scanf("%s",s);
    str2idx[s]=i;
  }
  rep(i,0,m){
    scanf("%s %s",s,t);
    mp[str2idx[s]][str2idx[t]]=1;
    mp[str2idx[t]][str2idx[s]]=1;
  }
  int ans=1;
  dp[0][0]=1;
  // 保持 i < j
  // dp[i][i] = 0 当 i!=0 时
  // 保证了dp[i][j]不会遗漏
  // 又i<j， 来源仅为dp[i][k]; 其中k<j
  //
  rep(i,0,n){
    rep(j,i+1,n){
      rep(k,0,j){
        if(mp[j][k]&&dp[i][k]&&dp[i][k]+1>dp[i][j]){
          dp[i][j]=dp[j][i]=dp[i][k]+1;
        }
      }
    }
    if(mp[i][n-1]){
      ans=max(ans,dp[i][n-1]);
    }
  }
  printf("%d\n",ans);
}
