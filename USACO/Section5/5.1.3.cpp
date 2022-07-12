/*
ID: 10157591
PROG: theme
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "theme";

// N <=5000
// 1~88 key on piano
// len >= 5
// 重复过(差),和至少另一个不相交
//
// 计算最长的 theme

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;

int a[5010];

int main(){
  usefile();
  cin>>n;
  rep(i,0,n){
    scanf("%d",a+i);
  }
  rep(i,0,n-1){
    a[i] = a[i+1]-a[i];
  }
  n--;
  int ans = 0;
  rep(i,0,min(n,n+5-2*ans)){
    int cnt = 0 ;
    rep(j,i+5,min(n,n+2-ans)){
      rep(len,0,min(j-i-1,n-j)){
        cnt ++;
        if(a[i+len] != a[j+len]){
          break;
        }
        ans = max(ans,len+2);
      }
    }
  }
  cout<<(ans<5?0:ans)<<endl;

  

  return 0;
}
