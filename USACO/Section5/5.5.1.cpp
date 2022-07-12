/*
ID: 10157591
PROG: picture
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "picture";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int N,ans=0;
// OX向和OY向的 线段分离处理，互不影响
tuple<int,bool,int,int> Lx[10010],Ly[10010]; // {位置idx坐标,结束边bool?,st->end}
int level[20010];


void Scan(tuple<int,bool,int,int> *L) {
  sort(L,L+N);
  rep(i,0,20001)
    level[i]=0;
  rep(i,0,N){
    rep(j,get<2>(L[i]),get<3>(L[i])){
      if (!get<1>(L[i])){
        ans += level[j+10000]==0;
        level[j+10000]++;
      } else {
        level[j+10000]--;
        ans += level[j+10000]==0;
      }
    }
  }
}


int main(){
  usefile();
  scanf("%d",&N);
  rep(i,0,N){
    int x1,x2,y1,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    // OX 方向边
    Lx[i*2] = {y1,false,x1,x2};
    Lx[i*2+1] = {y2,true,x1,x2};
    // OY 方向边
    Ly[i*2] = {x1,false,y1,y2};
    Ly[i*2+1] = {x2,true,y1,y2};
  }
  N*=2;
  Scan(Lx);
  Scan(Ly);
  printf("%d\n",ans);
  return 0;
}
