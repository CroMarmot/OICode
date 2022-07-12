/*
ID: 10157591
PROG: hidden
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "hidden";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

char s[100010];
int sz=0;

bool pos[100010];
vector<int>p;
vector<int>q;
int L;

bool circle(int idx,int len,int &newidx){
  newidx = (idx+L-len)%L;
  while(newidx != idx){
    if(!pos[newidx]){
      (newidx+=len)%=L;
      return false;
    }else{
      newidx = (newidx+L-len)%L;
    }
  }
  while(newidx - L > 0){
    newidx -= L;
  }
  printf("%d\n",newidx);
  return true;
}

int main(){
  usefile();
  // 同步增长，冲突取前，倍增 其余删除(因为保证最小)
  scanf("%d",&L);
  while(sz<L){
    scanf("%s",s+sz);
    sz+=strlen(s+sz);
  }
  char minch = s[0];
  rep(i,1,L){
    minch = min(minch,s[i]);
  }
  rep(i,0,L){
    if(s[i] == minch){
      p.push_back(i);
      pos[i]=true;
    }
  }
  int l = 1;
  while(p.size() > 1){
    int state = 0; // 0 for +1, 1 for *2
    minch = s[(p[0]+l)%L];
    for(auto idx : p){
      if(pos[(idx+l)%L] == true){
        state = 1;
        break;
      }
      minch = min(minch,s[(idx+l)%L]);
    }
    if(state == 0){
      q.clear();
      for(auto idx:p){
        if(!pos[idx])continue;
        if(s[(idx+l)%L] == minch){
          q.push_back(idx);
        }else{
          pos[idx]=false;
        }
      }
      p=q;
      l++;
    }else{
      q.clear();
      int startidx ;
      int ret = circle(p[0],l,startidx);
      if(ret){
        return 0;
      }
      int pidx = 0;
      for(pidx=0;pidx<p.size();pidx++){
        if(p[pidx] == startidx){
          break;
        }
      }
      rep(i,pidx,p.size()){
        int idx = p[i];
        if(!pos[idx])continue;
        if(pos[(idx+l)%L]){
          q.push_back(idx);
          pos[(idx+l)%L] = false;
        }else{
          pos[idx]=false;
        }
      }
      rep(i,0,pidx){
        int idx = p[i];
        if(!pos[idx])continue;
        if(pos[(idx+l)%L]){
          q.push_back(idx);
          pos[(idx+l)%L] = false;
        }else{
          pos[idx]=false;
        }
      }
      p=q;
      l*=2;
    }
  }
  printf("%d\n",p[0]);
  return 0;
}
