/*
ID: 10157591
PROG: rectbarn
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "rectbarn";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int L[3010],R[3010]; // j列当前线段 左右扩展的可行最远距离
int H[3010]; // j列 当前 的线段长度
bool g[3010][3010];
int n,m,ans;
int main(){
  usefile();
  freopen("rectbarn.in","r",stdin);
  freopen("rectbarn.out","w",stdout);
  int k;
  cin>>n>>m>>k;
  while(k--){
    int i,j;
    scanf("%d%d",&i,&j);
    g[i][j]=1;
  }
  rep(j,0,m+1){
    H[j]=0;
    L[j]=1;
    R[j]=m;
  }
  rep(i,1,n+1){
    // 处理所有 坏点
    rep(j,1,m+1){
      if(g[i][j]){
        H[j]=0;
        L[j]=1;
        R[j]=m;
      }
    }
    // 计算所有 左侧 和 右侧 最远
    int lm = 1;
    rep(j,1,m+1){
      if(!g[i][j]){
        H[j]++;
        L[j]=max(L[j],lm);
      } else{
        lm=j+1;
      }
    }
    int rm = m;
    per(j,1,m+1){
      if(!g[i][j]){
        R[j]=min(R[j],rm);
      }else{
        rm=j-1;
      }
    }
    // 计算面积
    rep(j,1,m+1){
      if(!g[i][j]){
        ans=max(ans,(R[j]-L[j]+1)*H[j]);
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
