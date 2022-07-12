/*
ID: 10157591
PROG: fence8
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "fence8";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;
int a[100];
int la[100];
int suma;
int R;
int r[1100];
int sumr[1100];

int dfs(int idx,int stn = n){
  if(suma < sumr[idx]){
    return false;
  }
  per(i,0,stn){
    if(a[i] < r[idx]){
      return false;
    }
    if(a[i] ==  a[i+1] && la[i] == la[i+1]){
      continue;
    }
    if(la[i] < r[idx]){
      continue;
    }
    if(idx == 0){
      return true;
    }
    la[i] -= r[idx];
    suma-=r[idx];
    bool predel = la[i] < r[0];
    if(predel){
      suma -= la[i];
    }
    int ret;
    if(idx > 0 && r[idx-1] == r[idx]){
      ret = dfs(idx-1,i+1);
    }else{
      ret = dfs(idx-1);
    }
    if(predel){
      suma += la[i];
    }
    suma+=r[idx];
    la[i] += r[idx];
    if(ret){
      return true;
    }
  }
  return false;
}

bool test(int idx){
  if(sumr[idx] > suma)return false;
  return dfs(idx);
}

int main(){
  usefile();
  scanf("%d",&n);
  rep(i,0,n){
    scanf("%d",a+i);
  }
  rep(i,0,n){
    la[i]=a[i];
    suma += a[i];
  }
  sort(a,a+n);

  scanf("%d",&R);
  rep(i,0,R){
    scanf("%d",r+i);
  }
  sort(r,r+R);
  if(r[0] > a[n-1]){
    cout<<0<<endl;
    return 0;
  }
  sumr[0]=r[0];
  rep(i,1,R){
    sumr[i]=sumr[i-1]+r[i];
  }
  int l=0,r=R;
  while(l+1<r){
    int mid = (l+r)/2;
    if(test(mid)){
      l = mid;
    }else{
      r = mid;
    }
  }
  cout<<l+1<<endl;
  return 0;
}
