/*
ID: 10157591
PROG: cryptcow
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "cryptcow";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}
const char Goal[] = "Begin the Escape execution at the Break of Dawn";
const int Mod = 999983;

char s[110];
int ans, cnt;
bool hsh[Mod];

// 删除a b c位置上的, 交换a->b b->c
void work(int a, int b, int c) {
  static char tmp[100];
  int len = strlen(s), tot = 0;
  for(int i = 0; i < a; ++i) {
    tmp[tot++] = s[i];
  }
  for(int i = b + 1; i < c; ++i) {
    tmp[tot++] = s[i];
  }
  for(int i = a + 1; i < b; ++i) {
    tmp[tot++] = s[i];
  }
  for(int i = c + 1; i < len; ++i) {
    tmp[tot++] = s[i];
  }
  tmp[tot] = 0;
  strcpy(s, tmp);
}

int getHash() {
  int ret = 0, len = strlen(s);
  for(int i = 0; i < len; ++i) {
    int num = (s[i]==' ')?1:(isupper(s[i]) ? s[i] - 'A' + 2 : s[i] - 'a' + 28);
    ret = (ret * 57 + num) % Mod;
  }
  return ret;
}

bool dfs(int depth) {
  if(strcmp(s, Goal) == 0) {
    ans = depth;
    return true;
  }
  int x = getHash();
  if(hsh[x]) {
    return false;
  }
  hsh[x] = true;
  ++cnt;
  // 被C O W 分割的 字串应该是Goal的连续子串
  static char sub[100];
  int len = strlen(s);
  int c[20], o[20], w[20];
  c[0] = o[0] = w[0] = 0;
  for(int i = 0, j = 0; i < len; ++i) {
    if(s[i] == 'C' || s[i] == 'O' || s[i] == 'W') {
      if(s[i] == 'C') {
        c[++c[0]] = i;
      }
      if(s[i] == 'O') {
        o[++o[0]] = i;
      }
      if(s[i] == 'W') {
        w[++w[0]] = i;
      }
      sub[j] = 0;
      if(!strstr(Goal, sub)) { //
        return false;
      }
      j = 0;
    }
    else {
      sub[j++] = s[i];
    }
  }
  // C = W = O
  if(o[0] != c[0] || o[0] != w[0] || w[0] != c[0]) {
    return false;
  }
  char pre[100];
  strcpy(pre, s); // 递归暂存
  // 查找顺序 先找O
  rep(j,1,o[0]+1){
    per(k,1,w[0]+1){
      if(w[k] < o[j])break;
      rep(i,1,c[0]+1){
      if(c[i] > o[j])break;
        work(c[i], o[j], w[k]);
        bool ret = dfs(depth + 1);
        if(ret){
          return true;
        }
        if(cnt > 200000) { // ............................
          return false;
        }
        strcpy(s, pre);
      }
    }
  }
  return false;
}


int main() {
  usefile();
  cin.getline(s,100);
  // scanf("%s",s);
  int ret = dfs(0);
  printf("%d %d\n", ret, ans);
  return 0;
}
