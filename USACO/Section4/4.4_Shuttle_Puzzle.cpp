/*
ID: 10157591
PROG: shuttle
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

#define W 1
#define B 2

using namespace std;

string filename = "shuttle";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}
int n;
int f[100]={0};

int ansi = 0;
int ans[1000]={0};

bool check(int * arr){
  int i;
  for(i=0;i<n;i++)
    if(arr[i] != B)
      return false;
  for(i=0;i<n;i++)
    if(arr[n+1+i] != W)
      return false;
  return true;
}
bool dfs(int * arr){
  if(check(arr))
    return true;
  int i;
  for(i=0;i<n*2+1;i++){
    if(arr[i] == 0)
      break;
  }
  int zeropos = i;
  if(zeropos > 0){
    if(arr[zeropos - 1] == W){
      ans[ansi++] = zeropos;
      // cout<<"["<<ansi-1<<"] = "<<ans[ansi-1]<<endl;
      arr[zeropos - 1] = 0;
      arr[zeropos] = W;
      if(dfs(arr))
        return true;
      arr[zeropos - 1] = W;
      arr[zeropos] = 0;
      ansi--;
    }else if(zeropos > 1 && arr[zeropos - 2] == W){
      ans[ansi++] = zeropos - 1;
      // cout<<"["<<ansi-1<<"] = "<<ans[ansi-1]<<endl;
      arr[zeropos - 2] = 0;
      arr[zeropos] = W;
      if(dfs(arr))
        return true;
      arr[zeropos - 2] = W;
      arr[zeropos] = 0;
      ansi--;
    }
  }
  if(zeropos < 2*n){
    if(arr[zeropos + 1] == B){
      ans[ansi++] = zeropos+2;
      // cout<<"["<<ansi-1<<"] = "<<ans[ansi-1]<<endl;
      arr[zeropos + 1] = 0;
      arr[zeropos] = B;
      if(dfs(arr))
        return true;
      arr[zeropos + 1] = B;
      arr[zeropos] = 0;
      ansi--;
    }else if(zeropos < 2*n - 1 && arr[zeropos + 2] == B){
      ans[ansi++] = zeropos + 3;
      // cout<<"["<<ansi-1<<"] = "<<ans[ansi-1]<<endl;
      arr[zeropos + 2] = 0;
      arr[zeropos] = B;
      if(dfs(arr))
        return true;
      arr[zeropos + 2] = B;
      arr[zeropos] = 0;
      ansi--;
    }
  }
  return false;
}


void printline(int index){
  int i;
  cout<<ans[index];
  for(i=1;index+i<ansi && i<20;i++)
    cout<<" "<<ans[index+i];
  cout<<endl;
}


void fuckformat(){
  int i;
  for(i=0;i<ansi;i+=20)
    printline(i);
}
int main(){
  usefile();
  cin>>n;
  int i;
  for(i=0;i<n;i++)
    f[i] = W;
  for(i=0;i<n;i++)
    f[n+i+1] = B;

  dfs(f);
  fuckformat();
  return 0;
}
