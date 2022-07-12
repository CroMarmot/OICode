/*
ID: 10157591
PROG: window
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

using namespace std;

const string filename = "window";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

list<int>Is[240][240]; // 大小猜的

vector<int>x;
vector<int>y;

vector<tuple<int,int> >q;

int itr = 0;
vector<tuple<int,int,int,int> >xys;

tuple<int,int,int,int> xyxy[123];

void rm(int ix,int iy,char I){
  for (list<int>::iterator it=Is[ix][iy].begin(); it!=Is[ix][iy].end(); ++it){
    if(*it == I){
      Is[ix][iy].erase(it);
      return ;
    }
  }
}

void top(int ix,int iy,char I){
  rm(ix,iy,I);
  Is[ix][iy].push_front(I);
}

void bot(int ix,int iy,char I){
  rm(ix,iy,I);
  Is[ix][iy].push_back(I);
}

int main(){
  usefile();
  char op;
  while(~scanf("%c",&op)){
    if(op!='w' && op!='t' && op!='b' && op!='d' && op!='s')continue;
    if(op == 'w'){
      char I;
      int x1,y1;
      int x2,y2;
      scanf("(%c,%d,%d,%d,%d)",&I,&x1,&y1,&x2,&y2);
      if(x1> x2){
        swap(x1,x2);
      }
      if(y1>y2){
        swap(y1,y2);
      }
      x.push_back(x1);
      x.push_back(x2);
      y.push_back(y1);
      y.push_back(y2);
      q.push_back({op,I});
      xys.push_back({x1,y1,x2,y2});
    }else{
      char I;
      scanf("(%c)",&I);
      q.push_back({op,I});
    }
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  for(auto item:q){
    int op = get<0>(item);
    int I = get<1>(item);
    if(op == 'w'){
      xyxy[I] = xys[itr++];
    }
    int x1idx=lower_bound(x.begin(),x.end(),get<0>(xyxy[I]))-x.begin();
    int y1idx=lower_bound(y.begin(),y.end(),get<1>(xyxy[I]))-y.begin();
    int x2idx=lower_bound(x.begin(),x.end(),get<2>(xyxy[I]))-x.begin();
    int y2idx=lower_bound(y.begin(),y.end(),get<3>(xyxy[I]))-y.begin();
    switch(op){
      case 'w':
        {
          rep(ix,x1idx,x2idx){
            rep(iy,y1idx,y2idx){
              Is[ix][iy].push_front(I);
            }
          }
          break;
        }
      case 't':
        {
          rep(ix,x1idx,x2idx){
            rep(iy,y1idx,y2idx){
              top(ix,iy,I);
            }
          }
          break;
        }
      case 'b':
        {
          rep(ix,x1idx,x2idx){
            rep(iy,y1idx,y2idx){
              bot(ix,iy,I);
            }
          }
          break;
        }
      case 'd':
        {
          rep(ix,x1idx,x2idx){
            rep(iy,y1idx,y2idx){
              rm(ix,iy,I);
            }
          }
          break;
        }
      case 's':
        {
          ll sshow = 0;
          rep(ix,x1idx,x2idx){
            rep(iy,y1idx,y2idx){
              sshow+= ((*Is[ix][iy].begin() == I)?(x[ix+1]-x[ix])*ll(y[iy+1]-y[iy]):0);
            }
          }
          ll scnt = (x[x2idx]-x[x1idx])*ll(y[y2idx]-y[y1idx]);
          printf("%.3lf\n",sshow*100/double(scnt));
          break;
        }
    }
  }
  return 0;
}
