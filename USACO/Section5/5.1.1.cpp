/*
ID: 10157591
PROG: fc
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "fc";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;

pair<double,double> base = {0,0};
pair<double,double>p[10010];

// 右手定则, v1在v2右侧 为正, v1在v2左侧为负
double cross(const pair<double,double>& v1,const pair<double,double>& v2){
  return v1.first * v2.second - v1.second * v2.first;
}

pair<double,double> operator - (const pair<double,double>& p1,const pair<double,double>& p2){
  return {p1.first-p2.first,p1.second-p2.second};
}

double abs(const pair<double,double> & p){
  return sqrt(p.first*p.first + p.second*p.second);
}

bool cmp(const pair<double,double>& p1,const pair<double,double>& p2){
  double c = cross(p1-base,p2-base);
  if(c != 0) return c>0;
  return abs(p1-base) < abs(p2-base);
}

pair<double,double> ans[10010];

int main(){
  usefile();
  cin>>n;
  if(n < 2){
    cout<<0<<endl;
    return 0;
  }
  rep(i,0,n){
    scanf("%lf %lf",&p[i].first,&p[i].second);
  }
  base = p[0];
  rep(i,0,n){
    if(base.second > p[i].second){
      base = p[i];
    }
  }
  sort(p,p+n,cmp);
  ans[0] = p[0];
  int cnt = 1;
  rep(i,1,n){
    while(cnt>1 && cross(ans[cnt-1]-ans[cnt-2],p[i]-ans[cnt-1]) <= 0){
      cnt--;
    }
    ans[cnt++] = p[i];
  }
  double output = 0;
  rep(i,0,cnt){
    output+=abs(ans[(i+1)%cnt]-ans[(i)%cnt]);
  }
  printf("%.2lf\n",output);

  return 0;
}
