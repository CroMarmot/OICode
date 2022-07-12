/*
ID: 10157591
PROG: fence3
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "fence3";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

double absarrow(double derx,double dery){
  return sqrt(derx*derx+dery*dery);
}

struct re{
  int x1,y1,x2,y2;
}l[160];
double dis(double x,double y,int idx){
  if(l[idx].x1==l[idx].x2){
    if(y<l[idx].y1)return absarrow(x-l[idx].x1,y-l[idx].y1);
    if(y>l[idx].y2)return absarrow(x-l[idx].x2,y-l[idx].y2);
    return fabs(x-l[idx].x1);
  }else{
    if(x<l[idx].x1)return absarrow(x-l[idx].x1,y-l[idx].y1);
    if(x>l[idx].x2)return absarrow(x-l[idx].x2,y-l[idx].y2);
    return fabs(y-l[idx].y1);
  }
}

int main(){
  usefile();
  srand(size_t(time(NULL)));
  int n=0;
  cin >> n;
  double x=rand()%100;
  double y=rand()%100;
  double step=100;
  tuple<double,double,double>ans;
  rep(i,0,n){
    scanf("%d %d %d %d", &l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
    // 因为平行于坐标轴 所以 必定有一组相等，所以只用换一组
    if(l[i].x1>l[i].x2)swap(l[i].x1,l[i].x2);
    if(l[i].y1>l[i].y2)swap(l[i].y1,l[i].y2);
    get<2>(ans) += dis(x,y,i);
  }
  int d=31;
  while(step>10e-3){
    rep(i,0,500){
      // 以任意方向 长度为step进行下降 d((x,y),(newx,newy)) = step
      double newx,newy;
      newx=step*(double(rand())/double(RAND_MAX))*(2*(rand()%2)-1); // [-step,step]
      newy=sqrt(step*step-newx*newx)*(2*(rand()%2)-1)+y; // 保证x y变化的向量长度是 step
      newx+=x;
      double lencnt=0;
      rep(idx,0,n){
        lencnt+=dis(newx,newy,idx);
      }
      // 如果更优下降
      if(lencnt-get<2>(ans)<0){
        x=newx;
        y=newy;
        ans={newx,newy,lencnt};
      }
    }
    d++;
    // 约从 1.1568910657987959 速率开始
    step/=log10(d)/log10(20);
  }
  printf("%.1lf %.1lf %.1lf\n",get<0>(ans),get<1>(ans),get<2>(ans));
  return 0;
}
