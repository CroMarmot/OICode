/*
ID: 10157591
PROG: race3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#define MOD 100000000

using namespace std;
ifstream inc("race3.in");
ofstream outc("race3.out");

int n;
vector<int> vto[100];
vector<int> ans;


void getinput(){
  for(n=0;;n++){
    int tmp;
    while(inc>>tmp){
      if(tmp == -2){
        break;
      }else if(tmp == -1){
        return ;
      }else{
        vto[n].push_back(tmp);
      }
    }
  }
  //check
  // int i;
  // for(i=0;i<n;i++){
  //   int j;
  //   for(j=0;j<vto[i].size();j++)
  //     cout<<i<<"->"<<vto[i][j]<<"\t";
  //   cout<<endl;
  // }
}

void tryi(int tryunavoid){
  int st,rear;
  st = 0;
  rear = 1;
  int vlist[100]={0};
  vlist[0]= 0;
  bool visit[100]={0};
  while(st<rear){
    int pick = vlist[st];
    for(int i=0;i<vto[pick].size();i++){
      if(vto[pick][i] == tryunavoid)
        continue;
      else if(vto[pick][i] == n-1)
        return ;
      else if(!visit[vto[pick][i]]){
        visit[vto[pick][i]]=true;
        vlist[rear++]=vto[pick][i];
      }
    }
    st++;
  }
  ans.push_back(tryunavoid);
}

void bfs(){
  int tryunavoid ;
  for(tryunavoid=1;tryunavoid<n-1;tryunavoid++){
    tryi(tryunavoid);
  }
}

bool circlecheck(int index){
  int st,rear;
  int vlist[100]={0};
  int vis[100]={0};
  int i;
  st = 0;
  rear=1;
  vlist[0]= 0;
  vis[0] = 1;
  while(st<rear){
    int pick = vlist[st];
    for(i=0;i<vto[pick].size();i++){
      if(index == vto[pick][i]){
        continue;
      }
      if(!vis[vto[pick][i]]){
        vis[vto[pick][i]] = 1;
        vlist[rear++] = vto[pick][i];
      }
    }
    st++;
  }

  st = 0;
  rear = 1;
  vlist[0] = index;

  while(st<rear){
    int pick = vlist[st];
    for(i=0;i<vto[pick].size();i++){
      if(index == vto[pick][i]){
        continue;
      }
      if(vis[vto[pick][i]] == 0){
        vis[vto[pick][i]] = 2;
        vlist[rear++] = vto[pick][i];
      }else if(vis[vto[pick][i]] == 1){
        return false;
      }
    }
    st++;
  }

  return true;
}

int main(){
  getinput();
  bfs();
  int i;
  outc<<ans.size();
  for(i=0;i<ans.size();i++){
    outc<<" "<<ans[i];
  }
  outc<<endl;
  vector<int> ans2;
  for(i=0;i<ans.size();i++){
    if(circlecheck(ans[i]))
      ans2.push_back(ans[i]);
  }
  outc<<ans2.size();
  for(i=0;i<ans2.size();i++){
    outc<<" "<<ans2[i];
  }
  outc<<endl;

  return 0;
}
