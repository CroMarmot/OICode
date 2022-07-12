/*
ID: 10157591
PROG: wissqu
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "wissqu";

pair<int,int> v[10][10];
char s[10][10];

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int cnt[10];
bool success = false;
int anscnt = 0;
tuple<char,int,int> pick[100];

int di[]={-1,-1,-1,0,0,0,1,1,1};
int dj[]={-1,0,1,-1,0,1,-1,0,1};

void dfs(int deep){
  if(deep == 16){
    anscnt++;
    if(!success){
      success = true;
      rep(i,0,16){
        printf("%c %d %d\n",get<0>(pick[i]),get<1>(pick[i]),get<2>(pick[i]));
      }
    }
    return ;
  }
  rep(k,0,5){
    if(deep == 0 && k != 3)continue;
    if(!cnt[k])continue;
    rep(i,0,4){
      rep(j,0,4){
        if(v[i][j].second)continue;
        bool conflict = false;
        rep(m,0,9){
          int newi = i+di[m];
          int newj = j+dj[m];
          if(newi < 0 || newj < 0 || newi > 4 || newj > 4){
            continue;
          }
          if(v[newi][newj].first == k){
            conflict = true;
            break;
          }
        }
        if(conflict)continue;
        auto old = v[i][j];
        v[i][j] = {k,1};
        pick[deep] = {'A'+k,i+1,j+1};
        cnt[k]--;
        dfs(deep+1);
        cnt[k]++;
        v[i][j] = old;
      }
    }
  }
}

int main(){
  usefile();
  rep(i,0,4){
    scanf("%s",s[i]);
  }
  cnt[0] = 3;
  cnt[1] = 3;
  cnt[2] = 3;
  cnt[3] = 4;
  cnt[4] = 3;
  rep(i,0,4){
    rep(j,0,4){
      v[i][j] = {s[i][j]-'A',0};
    }
  }
  dfs(0);
  printf("%d\n",anscnt);
  return 0;
}
