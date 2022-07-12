/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期二 2月 04, 2020 14:04:52 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

// 最大卡
// 1对
// 2对
// 3个同值
// 5顺
// 5同花
// 3同值+2同值
// 4同+1
// 同花顺
// t j Q K A 同花
//

char player[2][10][5];

int gv(char s){
  if(s>='2' && s<='9')return s-'0';
  if(s=='T')return 10;
  if(s=='J')return 11;
  if(s=='Q')return 12;
  if(s=='K')return 13;
  if(s=='A')return 14;
  cout<<s<<endl;
  assert(false);
  return -1;
}


vector<int> calc(int idx){
  // 0 最大卡
  // 1 1对
  // 2 2对
  // 3 3个同值
  // 4 5顺
  // 5 5同花
  // 6 3同值+2同值
  // 7 4同+1
  // 8 同花顺
  // 9 t j Q K A 同花

  vector<pair<int,int> > xxx;
  rep(i,0,5){
    xxx.pb({gv(player[idx][i][0]),player[idx][i][1]-'A'});
  }
  sort(xxx.begin(),xxx.end());

  // 9 t j Q K A 同花
  if(xxx[0].first == 9
      && xxx[0].first+1 == xxx[1].first
      && xxx[1].first+1 == xxx[2].first
      && xxx[2].first+1 == xxx[3].first
      && xxx[3].first+1 == xxx[4].first

      && xxx[0].second == xxx[1].second
      && xxx[1].second == xxx[2].second
      && xxx[2].second == xxx[3].second
      && xxx[3].second == xxx[4].second
    ){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        9
    };
  }
  // 8 同花顺
  if(
      xxx[0].first+1 == xxx[1].first
      && xxx[1].first+1 == xxx[2].first
      && xxx[2].first+1 == xxx[3].first
      && xxx[3].first+1 == xxx[4].first

      && xxx[0].second == xxx[1].second
      && xxx[1].second == xxx[2].second
      && xxx[2].second == xxx[3].second
      && xxx[3].second == xxx[4].second
    ){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        8
    };
  }
  // 7 4同+1
  if(
      (xxx[0].first == xxx[1].first
       && xxx[0].first == xxx[2].first
       && xxx[0].first == xxx[3].first) ||
      (xxx[4].first == xxx[1].first
       && xxx[4].first == xxx[2].first
       && xxx[4].first == xxx[3].first)
    ){
    return {
      xxx[0].first+xxx[4].first-xxx[2].first,
        xxx[2].first,
        xxx[2].first,
        xxx[2].first,
        xxx[2].first,
        7
    };
  }
  // 6 3同值+2同值
  if(
      (xxx[0].first == xxx[1].first
       && xxx[2].first == xxx[3].first
       && xxx[2].first == xxx[4].first) ||
      (xxx[3].first == xxx[4].first
       && xxx[0].first == xxx[1].first
       && xxx[0].first == xxx[2].first)
    ){
    return {
      xxx[1].first+xxx[3].first-xxx[2].first,
        xxx[1].first+xxx[3].first-xxx[2].first,
        xxx[2].first,
        xxx[2].first,
        xxx[2].first,
        6
    };
  }
  // 5 5同花
  if(
      xxx[0].second == xxx[1].second
      && xxx[0].second == xxx[2].second
      && xxx[0].second == xxx[3].second
      && xxx[0].second == xxx[4].second
    ){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        5
    };
  }
  // 4 5顺
  if(
      xxx[0].first+1 == xxx[1].first
      && xxx[1].first+1 == xxx[2].first
      && xxx[2].first+1 == xxx[3].first
      && xxx[3].first+1 == xxx[4].first
    ){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        4
    };
  }
  // 3 3同值
  if(xxx[0].first == xxx[1].first
      && xxx[0].first == xxx[2].first){
    return {
      xxx[3].first,
        xxx[4].first,
        xxx[0].first,
        xxx[0].first,
        xxx[0].first,
        3
    };
  }
  if(xxx[1].first == xxx[2].first
      && xxx[2].first == xxx[3].first){
    return {
      xxx[0].first,
        xxx[4].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        3
    };
  }
  if(xxx[2].first == xxx[3].first
      && xxx[3].first == xxx[4].first){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        3
    };
  }
  // 2 pair
  if(xxx[0].first == xxx[1].first
      && xxx[2].first == xxx[3].first){
    return {
      xxx[4].first,
        xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        2
    };
  }
  if(xxx[0].first == xxx[1].first
      && xxx[3].first == xxx[4].first){
    return {
      xxx[2].first,
        xxx[0].first,
        xxx[1].first,
        xxx[3].first,
        xxx[4].first,
        2
    };
  }
  if(xxx[1].first == xxx[2].first
      && xxx[3].first == xxx[4].first){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        2
    };
  }
  // 1 pair
  if(xxx[0].first == xxx[1].first){
    return {
      xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        xxx[0].first,
        xxx[1].first,
        1
    };
  }
  if(xxx[1].first == xxx[2].first){
    return {
      xxx[0].first,
        xxx[3].first,
        xxx[4].first,
        xxx[1].first,
        xxx[2].first,
        1
    };
  }
  if(xxx[2].first == xxx[3].first){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[4].first,
        xxx[2].first,
        xxx[3].first,
        1
    };
  }
  if(xxx[3].first == xxx[4].first){
    return {
      xxx[0].first,
        xxx[1].first,
        xxx[2].first,
        xxx[3].first,
        xxx[4].first,
        1
    };
  }
  return {
    xxx[0].first,
      xxx[1].first,
      xxx[2].first,
      xxx[3].first,
      xxx[4].first,
      0
  };
}

int win(){
  vector<int>v0 = calc(0);
  vector<int>v1 = calc(1);
  // rep(i,0,6){
  //   printf("v0[%d]",v0[i]);
  // }
  // cout<<endl;
  // rep(i,0,6){
  //   printf("v1[%d]",v1[i]);
  // }
  // cout<<endl;
  per(i,0,6){
    if(v0[i] > v1[i])return 1;
    if(v1[i] > v0[i])return 2;
  }
  cout<<"ping ju"<<endl;
  return -1;
}


int main(){
  int win1 = 0;
  rep(i,0,1000){
    rep(j,0,2){
      rep(k,0,5){
        scanf("%s",player[j][k]);
      }
    }
    win1 += win() == 1;
  }
  cout<<win1<<endl;
  return 0;
}

// time cat p054_poker.txt | ./p059
