/*
ID: 10157591
PROG: cowcycle
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "cowcycle";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int s1[20],s2[20];
int ans1[20],ans2[20];
int F,F1,F2;
int R,R1,R2;
int cnt;
double rate[100],diff[100];
double minvf=10000000;

void count(){
  int k=0;
  double sum=0,avg,vf=0,sumf=0,p;
  // 数据量小 采用插入排序
  rep(i,0,F){
    rep(j,0,R){
      p=(double)s1[i]/s2[j];
      int l=++k;
      while (rate[l-1]>=p) {
        rate[l]=rate[l-1];
        l--;
      }
      rate[l]=p;
    }
  }
  rep(i,1,cnt){
    diff[i]=rate[i+1]-rate[i];
    sum+=diff[i];
    sumf+=diff[i]*diff[i];
  }
  avg=sum/(cnt-1);// 相邻值的差的个数 比值的个数少1
  vf=sumf-sum*avg;
  if (vf<minvf)  {
    minvf=vf;
    memcpy(ans1,s1,sizeof(int)*F);
    memcpy(ans2,s2,sizeof(int)*R);
  }
}

// 枚举后齿轮 从w 到R2-R+k+1
void sc2(int k,int w){
  if (k==R){
    if (s1[F-1]*s2[R-1]<3*s1[0]*s2[0]) // 题目限制条件剪枝
      return;
    count();
    return;
  }
  rep(i,w,R2-R+k+2){
    s2[k]=i;
    sc2(k+1,i+1);
  }
}

// 枚举前齿轮 从w到F2-F+k+1
void sc1(int k,int w){
  if (k==F)  {
    sc2(0,R1);
    return;
  }
  rep(i,w,F2-F+k+2){
    s1[k]=i;
    sc1(k+1,i+1);
  }
}

int main() {
  usefile();
  cin>> F >> R >> F1 >> F2 >> R1 >> R2;
  cnt=F*R;
  sc1(0,F1);
  rep(i,0,F){
    cout << ans1[i] << " \n"[i==F-1];
  }
  rep(i,0,R){
    cout << ans2[i] << " \n"[i==R-1];
  }
  return 0;
}
