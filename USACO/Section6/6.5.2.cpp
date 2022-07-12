/*
ID: 10157591
PROG: fence4
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "fence4";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}


pair<int,int> p;
pair<int,int> P[210];
int N;


double cross(pair<double,double> a,pair<double,double> b){
  return a.first*b.second-a.second*b.first;
}

pair<double,double> operator + (pair<double,double> a,pair<double,double> b)  {
  return {a.first+b.first,a.second+b.second};
}

pair<double,double> operator - (pair<double,double> a,pair<double,double> b)   {
  return {a.first-b.first,a.second-b.second};
}

bool isIntersect(pair<pair<double,double>,pair<double,double>> line1,pair<pair<double,double>,pair<double,double>> line2){
  return  !(
      (cross(line1.first -line2.first,line2.second-line2.first) > 0) ==
      (cross(line1.second-line2.first,line2.second-line2.first) > 0) ||
      (cross(line2.first -line1.first,line1.second-line1.first) > 0) ==
      (cross(line2.second-line1.first,line1.second-line1.first) > 0)
      );

}

bool isValid(){
  rep(i,0,N){
    rep(j,i+2,N){
      if(i == 0 && j == N-1)continue;
      if(isIntersect({P[i],P[i+1]}, {P[j],P[(j+1)%N]})){
        return false;
      }
    }
  }
  return true;
}

// 共线
bool isColine(int idx){
  return cross(P[idx]-P[(idx+1)%N],p) == cross(P[idx],P[(idx+1)%N]);
}

bool isSeen(int idx){
  int x1 = P[idx].first;
  int y1 = P[idx].second;
  int nsegments = 1000;
  rep(i,1,nsegments){
    pair<double,double> point_ =  {
      x1 + i * 1.0 / nsegments * (P[(idx + 1) % N].first  - x1),
      y1 + i * 1.0 / nsegments * (P[(idx + 1) % N].second - y1)};
    bool blocked = false;
    rep(j,0,N){
      if(j == idx)      {
        continue;
      }
      if(isIntersect({p,point_}, {P[j],P[(j+1)%N]})){
        blocked = true;
        break;
      }
    }
    if(!blocked)    {
      return true;
    }
  }
  return false;
}

vector<int> ans;
int main(){
  usefile();
  scanf("%d", &N);
  scanf("%d %d", &p.first,&p.second);
  rep(i,0,N){
    scanf( "%d %d", &P[i].first, &P[i].second);
  }
  if(!isValid())  {
    printf( "NOFENCE\n");
    return 0;
  }
  rep(i,0,N){
    if(!isColine(i) && isSeen(i))    {
      ans.push_back(i);
    }
  }
  if(ans.size() >= 2 && ans[ans.size() - 2] == N - 2){
    ans[ans.size() - 2] = N - 1;
    ans[ans.size() - 1] = N - 2;
  }
  printf("%d\n", int(ans.size()));
  rep(i,0,ans.size()){
    if(ans[i] == N - 1)    {
      printf("%d %d %d %d\n", P[0].first, P[0].second, P[ans[i]].first, P[ans[i]].second);
    }else{
      printf( "%d %d %d %d\n", P[ans[i]].first, P[ans[i]].second, P[ans[i] + 1].first, P[ans[i] + 1].second);
    }
  }
  return 0;
}
