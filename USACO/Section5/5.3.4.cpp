/*
ID: 10157591
PROG: bigbrn
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "bigbrn";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n,t;

// bitset<8> A[1010][130];// [1010][1010]; // N*N
// bitset<8> B[1010][130];// [1010][1010]; // (N+1-len)*N
// //bitset<8> C[1010][130];// [1010][1010]; // (N+1-len)*(N+1-len)

int A[1010][1010];
int B[1010][1010];

// void setv(bitset<8> *arr,int idx,int v){
//   arr[idx/8].set(idx%8,bool(v));
// }
//
// int getv(bitset<8> *arr,int idx){
//   return arr[idx/8][idx%8];
// }

void setv(int *arr,int idx,int v){
  arr[idx]=v;
}

int getv(int *arr,int idx){
  return arr[idx];
}

bool ok(int len){
  if(len == 0)return true;
  // A->B
  rep(j,0,n){
    int cnt = 0;
    rep(i,0,len){
      cnt+=getv(A[i],j);
    }
    setv(B[0],j,cnt);
    rep(i,1,n+1-len){
      cnt+=getv(A[i+len-1],j)-getv(A[i-1],j);
      setv(B[i],j,cnt);
    }
  }
  // B->C
  rep(i,0,n+1-len){
    int cnt= 0;
    rep(j,0,len)
      cnt+=getv(B[i],j);
    if(cnt == 0)return true;
    rep(j,1,n+1-len){
      cnt+=getv(B[i],j+len-1)-getv(B[i],j-1);
      if(cnt == 0)return true;
    }
  }
  return false;
}

bool all1(){
  rep(i,0,n){
    rep(j,0,n){
      if(A[i][j] == 0){
        return false;
      }
    }
  }
  return true;
}

int main(){
  usefile();
  cin>>n>>t;
  rep(i,0,t){
    int x,y;
    scanf("%d %d",&x,&y);
    setv(A[x-1],y-1,1);
  }

  int lenl=0,lenr=n+1;
  while(lenl+1<lenr){
    int mid=(lenl+lenr)/2;
    if(ok(mid)){
      lenl=mid;
    }else{
      lenr=mid;
    }
  }
  cout<<lenl<<endl;

  return 0;
}
