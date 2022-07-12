/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期五 2月 07, 2020 14:56:27 CST
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


// awk -F, '{ print NF }'  p059_cipher.txt

// awk -F, '{ print $i }'  p059_cipher.txt
// awk -F, '{ for(i=1;i<=NF;i++){print $i;} }'  p059_cipher.txt | ./p059

const int N = 1455;
int s[1510];

char encry[10];

void dfs(int idx=0){
  if(idx==3){
    bool ok = true;
    rep(j,0,N){
      int ch = s[j] ^ encry[j%3];
      if(ch < 32 || ch >= 127){
        ok = false;
        break;
      }
    }
    // 结尾句号
    if( (s[N-1] ^ encry[(N-1)%3] ) !='.'){
      ok = false;
    }
    if(ok){
      cout<<encry<<endl;
      int sum = 0;
      rep(j,0,N){
        printf("%c",char(s[j]^encry[j%3]));
        sum+=s[j]^encry[j%3];
      }
      printf("\n");
      printf("sum=%d\n",sum);
    }
    return ;
  }
  rep(i,'a','z'){
    encry[idx]=i;
    dfs(idx+1);
  }
}

int main(){
  rep(i,0,N){
    scanf("%d",s+i);
  }
  dfs();
  return 0;
}

// time cat p059_cipher.txt  | ./p059
