/*
ID: 10157591
PROG: ditch
LANG: C++
*/
#include <iostream>
#include <fstream>

#define MAXF 10000000

using namespace std;
ifstream inc("ditch.in");
ofstream outc("ditch.out");


int val[210][210]={0};

int n, m;

int minn(int v1,int v2){
  return v1<v2?v1:v2;
}

int bfs(){
  int pre[210]={0};
  int stacks[210]={0};
  int waterleft[210]={0};

  int st=0,rear=1;
  waterleft[1] = MAXF;
  stacks[0]=1;
  while(st<rear){
    int thisindex = stacks[st];
    int i;
    for(i=2;i<=m;i++){
      if(val[thisindex][i]){
        if(pre[i] == 0 ){
          stacks[rear++] = i;
          pre[i] = thisindex;
          waterleft[i] = minn(waterleft[thisindex],val[thisindex][i]);
          if(i==m)
            break;
        }else if(waterleft[i] < minn(waterleft[thisindex],val[thisindex][i])){
          pre[i] = thisindex;
          waterleft[i] = minn(waterleft[thisindex],val[thisindex][i]);
          if(i==m)
            break;
        }
      }
    }
    if(i==m)
      break;
    st++;
  }

  if(st == rear)
    return -1;

  int newcost = waterleft[m];
  int oldindex = m;
  int thisindex = pre[oldindex];
  while(thisindex!=0){
    val[thisindex][oldindex] -= newcost;
    val[oldindex][thisindex] += newcost;
    oldindex = thisindex;
    thisindex = pre[oldindex];
  }

  // int i,j;
  // cout<<"----------------"<<endl;
  // for(i=1;i<=m;i++){
  //   for(j=1;j<=m;j++){
  //     cout<<val[i][j]<<"\t";
  //   }
  //   cout<<endl;
  // }
  // cout<<"----------------"<<endl;
  return newcost;
}



int main(){
  inc>>n>>m;
  int i;
  for(i=0;i<n;i++){
    int f,t,v;
    inc>>f>>t>>v;
    val[f][t]+=v;
  }
  int ans=0,ret;
  while((ret = bfs())!=-1)
    ans += ret;
  outc<<ans<<endl;
  return 0;
}

