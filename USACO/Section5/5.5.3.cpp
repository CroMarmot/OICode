/*
ID: 10157591
PROG: twofive
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "twofive";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

char s[100]; // 按位逼近的
char str[100]; // str2index

int dp[6][6][6][6][6];

int dfs(int a=0, int b=0, int c=0, int d=0, int e=0, char ch='A') {
  if(ch > 'Y') return 1;
  int &ret = dp[a][b][c][d][e];
  if(ret) return ret;
  // 每一行 一定小于等于上一行
  int w = 5;
  int *v[6]={&w,&a,&b,&c,&d,&e};
  rep(i,1,6){
    // 未填过 和 已经填过(按照 字母顺序扩展)
    int idx = *v[i]+(i-1)*5;
    if(*v[i] < *v[i-1] && (s[idx] == 0 || s[idx] == ch)){
      (*v[i])++;
      ret+=dfs(a,b,c,d,e,ch+1);
      (*v[i])--;
    }
  }
  return ret;
}

void index2word(){
  int n;
  scanf("%d",&n);
  rep(i,0,25){
    for(s[i] = 'A';; s[i]++) { // 按位逼近 时间复杂度25×25
      memset(dp, 0,sizeof(dp));
      int ret = dfs();
      // cout<<i<<" = "<<s[i]<<"\tret = "<<ret<<endl;
      if(ret >= n) break;
      n -= ret;
    }
  }
  printf("%s\n", s);
}

void word2index(){
  scanf("%s", str);
  int ans = 1;
  rep(i, 0, 25)  {
    for(s[i] = 'A'; s[i] < str[i]; s[i]++) {
      memset(dp, 0,sizeof(dp));
      ans += dfs();
    }
  }
  printf("%d\n", ans);
}

int main(){
  usefile();
  char c;
  cin >> c;
  if(c == 'N')  { // index 2 word
    index2word();
  } else if(c == 'W')  { // word 2 index
    word2index();
  }
  return 0;
}
