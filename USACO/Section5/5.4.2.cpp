/*
ID: 10157591
PROG: charrec
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "charrec";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n,m;
char str[]=" abcdefghijklmnopqrstuvwxyz";
char s[30][30][30];// 标准字符集[idx][i][j]
char t[1210][30]; // 目标字符串[i][j]
int diff[30][30][1210]; // 预处理 [字符idx][字符的i行][目标的j行] = 01差异和
tuple<int,int,int>dp[1210]; // {最小代价，父节点，字符}
const int SUP = 1000000;


// 从st行开始匹配len行，返回{最小的代价，匹配的字符};
pair<int,int> solve(int st,int len){
  pair<int,int>ret= {SUP,-1};
  rep(i,0,27){
    if(len==20){
      int sum=0;
      rep(k,0,20){
        sum+=diff[i][k][st+k];
      }
      ret= min(ret,{sum,i});
    }else{
      // 这边重复计算了， 这里可以用前缀和 后缀和继续优化, 目测可以优化掉约10-20倍性能
      // 不过因为USACO的数据比较小 这样已经是0.1s内了 就没写优化了
      rep(j,0,20){ // 枚举删掉或增加的行
        int p=st,sum=0;
        rep(k,0,j){
          sum+=diff[i][k][p++];
        }
        if(len==21){ // 19为删掉 21为增加
          sum+=diff[i][j][p++];
          sum+=diff[i][j][p++];
        }
        rep(k,j+1,20){
          sum+=diff[i][k][p++];
        }
        ret= min(ret,{sum,i});
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  freopen("font.in","r",stdin);
  freopen("charrec.out","w",stdout);
  scanf("%d",&n);
  rep(idx,0,27){
    rep(i,0,20){
      scanf("%s",s[idx][i]);
    }
  }
  fclose(stdin);
  freopen("charrec.in","r",stdin);
  scanf("%d",&m);
  rep(i,0,m){
    scanf("%s",t[i]);
    dp[i] = {SUP,0,0};
  }
  // 预处理 把每个字符的每一行 都和 目标字符比
  // 目标k行 和 第x个字符 的y行 比较不同的01个数
  rep(idx,0,27){
    rep(i,0,20){
      rep(mm,0,m){
        rep(j,0,20){
          diff[idx][i][mm]+=s[idx][i][j]!=t[mm][j];
        }
      }
    }
  }
  rep(i,18,m){
    rep(len,19,22){
      auto [cost,idx]=solve(i-len+1,len);
      dp[i] = min(dp[i], {cost+(i-len<0?0:get<0>(dp[i-len])),i-len,idx});
    }
  }
  vector<char>ans;
  int i=m-1;
  do{
    ans.push_back(str[get<2>(dp[i])]);
  }while((i=get<1>(dp[i]))>0);
  per(itr,0,ans.size()){
    printf("%c",ans[itr]);
  }
  printf("\n");
  return 0;
}
