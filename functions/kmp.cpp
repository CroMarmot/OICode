#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=a;i<(int)n;i++)

// #号拼接, S#T
class KMP {
  private :
    vector<int> f; // 比它小的最长前缀的长度
    const char *s;
    int sz;
  public:
    KMP(const char *s,int sz):s(s),sz(sz){
      f = vector<int>(sz,0);
      int fa = 0;
      rep(i,1,sz){
        while (fa && s[i] != s[fa]) fa = f[fa-1];
        if (s[i] == s[fa]) fa++;
        f[i] = fa;
      }
    }
    vector<int> getPrefixLen(){
      return f;
    }
    int posIn(const char *t,int szt) {
      int fa = 0;
      rep(i,0,szt) {
        while (fa && t[i] != s[fa]) fa = f[fa-1];
        if (t[i] == s[fa]) fa++;
        if (fa == sz) return i-fa+1;
      }
      return -1;
    }
};

int main(){
  char s[100] = "hello";
  auto kmp = new KMP(s,5);
  vector<string> qs = {"test string hello world!","test string hell world!"};
  for(auto si:qs){
    cout<<kmp->posIn(si.c_str(),si.size())<<endl;
  }
  return 0;
}

// 期望 记录每个位置作为后缀结尾 匹配 查询字符串的最长前缀长度
// next/f 记录 上一个相等长度
//
// `要搜的#被搜的` 拼在一起,做一轮kmp判断长度也是一个办法
