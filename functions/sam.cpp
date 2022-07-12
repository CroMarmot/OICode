#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)

struct State {
  State * link; // 后缀父状态 指向比它短的后缀状态
  unordered_map<int, State *> next; // 状态转移, 指向string尾部增加int后得到的State
  int maxLen; // maxlen in this state
  State(int _maxLen):
    link(NULL),maxLen(_maxLen){
      next = {};
    }
};

class SAM{
  State *root , *lastState;
public:
  SAM(){
    root = lastState = new State(0);
  }
  void extend(int w){ // ???? => ????w
    State *p = lastState;
    State *newState = new State(p->maxLen + 1);
    // find first p in lastState->link->link->link...->link
    //  satisfy p->next[w] exist
    //  let q = p->next[w]
    //  找到有 w 转移的, 或者增加w转移
    for(;p && !p->next[w];p=p->link) p->next[w] = newState;
    for(;;){ // 降低层级
      if(!p){ // 全部原来都没有w转移, 也就是 [...??w] 唯一存在
        newState -> link = root;
        break;
      }
      // state p + char w -> state q
      State *q = p->next[w]; // 说明 [p w] 至少两处存在
      if(p->maxLen+1 == q->maxLen){ // 单独状态
        newState->link = q; // newState 一定比 q 长, q是比它短的最长后缀
        break;
      }
      // clone q next & link
      State * qClone = new State(p->maxLen+1); // 相当于从State q中拆出不大于p->next[w]转移的部分
      qClone->next = q->next; // copy
      qClone->link = q->link;
      // change q & newState link
      for(;p && p->next[w] == q;p=p->link) p->next[w] = qClone; // 更新所有单独
      q->link = newState->link = qClone;
      break;
    }
    lastState = newState;
  }

  bool has(string s){
    State *p = root;
    for(auto ch:s){
      if(!p->next[ch])return false;
      p = p->next[ch];
    }
    return true;
  }
};

int main(){
  auto sam = SAM();
  string s = "aabab";
  for(auto ch: s){
    sam.extend(ch);
  }
  printf("%d\n",(int)sam.has("aba"));
  return 0;
}
