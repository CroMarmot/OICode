/*
ID: 10157591
PROG: starry
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;

const string filename = "starry";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

char s[110][110];

vector<vector<pair<int,int> > >v2pointlist;

int n,m;
int curc = 0;

int deri[] = {-1,-1,-1,0,0,1,1,1};
int derj[] = {-1,0,1,-1,1,-1,0,1};

pair<int,int> stk[10010];
vector<bool>vis;

vector<pair<int,int> > v;

bool same(const vector<pair<int,int> >&v1,const vector<pair<int,int> >&v2){
  rep(i,0,v1.size()){
    if(v1[i] != v2[i]){
      return false;
    }
  }
  return true;
}

bool isSame(const vector<pair<int,int> >&v1,const vector<pair<int,int> >&v2){
  if(v1.size()!=v2.size())
    return false;
  int maxi = 0,maxj=0;
  rep(i,0,v2.size()){
    maxi = max(maxi,v2[i].first);
    maxj = max(maxj,v2[i].second);
  }
  if(same(v1,v2))return true;
  v.clear();
  rep(i,0,v2.size()){
    v.pb({v2[i].first,maxj-v2[i].second});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  v.clear();
  rep(i,0,v2.size()){
    v.pb({maxi-v2[i].first,v2[i].second});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  v.clear();
  rep(i,0,v2.size()){
    v.pb({maxi-v2[i].first,maxj-v2[i].second});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  
  v.clear();
  rep(i,0,v2.size()){
    v.pb({v2[i].second,v2[i].first});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  v.clear();
  rep(i,0,v2.size()){
    v.pb({maxj-v2[i].second,v2[i].first});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  v.clear();
  rep(i,0,v2.size()){
    v.pb({v2[i].second,maxi-v2[i].first});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  v.clear();
  rep(i,0,v2.size()){
    v.pb({maxj-v2[i].second,maxi-v2[i].first});
  }
  sort(v.begin(),v.end());
  if(same(v1,v))return true;
  return false;
}

void bfs(int i,int j){
  vis.clear();
  vis.resize(10000);
  stk[0] = {i,j};
  vis[i*100+j] = true;
  int st = 0,rear=1;
  while(st < rear){
    auto [_i,_j] = stk[st];
    rep(k,0,8){
      int newi = _i + deri[k];
      int newj = _j + derj[k];
      if(newi < 0 || newi >= m || newj < 0 || newj >= n)continue;
      if(s[newi][newj] == '0')continue;
      if(vis[newi*100+newj])continue;
      vis[newi*100+newj] = true;
      stk[rear++]= {newi,newj};
    }
    st++;
  }
  int mini = i;
  int minj = j;
  rep(k,0,rear){
    mini = min(mini,stk[k].first);
    minj = min(minj,stk[k].second);
  }
  vector<pair<int,int> > poss;
  rep(k,0,rear)
    poss.pb({stk[k].first-mini,stk[k].second-minj});
  sort(poss.begin(),poss.end());

  int pickcolor = -1;
  for(int i=0;i<v2pointlist.size();i++){
    if(isSame(v2pointlist[i],poss)){
      pickcolor = i;
      break;
    }
  }
  if(pickcolor == -1){
    pickcolor = v2pointlist.size();
    v2pointlist.pb(poss);
  }
  rep(i,0,rear){
    s[stk[i].first][stk[i].second] = 'a'+pickcolor;
  }
}

int main(){
  usefile();
  cin>>n>>m;
  rep(i,0,m){
    scanf("%s",s[i]);
  }
  rep(i,0,m){
    rep(j,0,n){
      if(s[i][j] != '1')continue;
      bfs(i,j);
    }
  }
  rep(i,0,m)
    printf("%s\n",s[i]);

  return 0;
}
