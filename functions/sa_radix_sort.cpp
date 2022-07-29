#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=n;i-->(ll)a;)
#define pb push_back

const int N = 1000000;

bool eq(vector<int>& rk, int x,int y,int w){
  return rk[x] == rk[y] && rk[x+w] == rk[y+w];
}

// 0-index + 基数排序
void calcsa(char *s,int n, vector<int> &sa,vector<int> &rk){
  const int SIZE = max(512, n+1); // 字符集大小
  vector<int>cnt(SIZE, 0); // char 2 count
  rk.resize(2*n); // rank: 相等的前缀rank相等, 结束符rank = 0, 所以rank从1开始
  sa.resize(n); // 后缀 index
  rep(i,0,n) ++cnt[rk[i] = s[i]]; // 计数统计
  rep(i,1,SIZE) cnt[i] += cnt[i - 1]; // 计数统计前缀
  per(i,0,n) sa[--cnt[rk[i]]] = i; // 当前排序
  { // n == 1
    auto oldrk = rk;
    int p = 0;
    rep(i,0,n) {
      if (i == 0 || oldrk[sa[i]] != oldrk[sa[i-1]]) p++;
      rk[sa[i]] = p;
    }
  }
  // rk = sort({rk[i],rk[i+w]}
  for(int w = 1; w < n; w *= 2) {
    // 从低位到高位排序, 先排低位 rank[i+w], 再排 rank[i+0]
    for(auto d:{w, 0}){
      cnt = vector(SIZE,0);
      rep(i,0,n) ++cnt[rk[i + d]]; // 所有 i+d 开始的计数统计
      rep(i,1,SIZE) cnt[i] += cnt[i - 1];// 前缀和(基数排序
      auto idx = sa;
      per(i,0,n) sa[--cnt[rk[idx[i] + d]]] = idx[i]; // 保序
    }
    auto oldrk = rk;
    int p = 0;
    rep(i,0,n) {
      if (i == 0 || oldrk[sa[i]] != oldrk[sa[i-1]] || oldrk[sa[i]+w] != oldrk[sa[i - 1] + w]) p++;
      rk[sa[i]] = p;
    }
  }
  rk.resize(n+1);
}

int main() {
  char s[N+10] = "aabaaaab";
  int n = strlen(s) ;
  printf("%d\n",n);
  printf("%s\n",s);
  vector<int> sa;
  vector<int> rank;
  calcsa(s, n, sa, rank);
  rep(i,0,n) printf("%d ", sa[i]);
  return 0;
}
