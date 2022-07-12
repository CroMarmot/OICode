/*
ID: 10157591
PROG: job
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
ifstream inc("job.in");
ofstream outc("job.out");

int cmp1(const void * v1, const void * v2){
  return *(int *) v1 - *(int *)v2;
}
int cmp2(const void * v1, const void * v2){
  return *(int *) v2 - *(int *)v1;
}
int maxx(int v1,int v2){
  return v1>v2?v1:v2;
}
int n,m1,m2;
int A[40],B[40];
int DA[40]={0},DB[40]={0};
int ANSA[1010]={0};
int ANSB[1010]={0};
int main(){
  int i;
  inc>>n>>m1>>m2;
  for(i=0;i<m1;i++){
    inc>>A[i];
  }
  for(i=0;i<m2;i++){
    inc>>B[i];
  }
  int j;
  for(i=0;i<n;i++){
    int ans_j = 0;
    for(j=0;j<m1;j++){
      if(DA[j]+A[j] < DA[ans_j]+A[ans_j])
        ans_j = j;
    }
    DA[ans_j]+=A[ans_j];
    ANSA[i] = DA[ans_j];
  }

  for(i=0;i<n;i++){
    int ans_j = 0;
    for(j=0;j<m2;j++){
      if(DB[j]+B[j] < DB[ans_j]+B[ans_j])
        ans_j = j;
    }
    DB[ans_j]+=B[ans_j];
    ANSB[i] = DB[ans_j];
  }

  qsort(ANSA,n,sizeof(int),cmp1);
  qsort(ANSB,n,sizeof(int),cmp2);
  
  int ans0=0, ans1 = 0 ;
  for(i=0;i<n;i++){
    ans0 = maxx(ans0,ANSA[i]);
    ans1 = maxx(ans1,ANSA[i]+ANSB[i]);
  }
  outc<<ans0<<" "<<ans1<<endl;
  return 0;
}
