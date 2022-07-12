
/*
ID: 10157591
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
struct p
{
    int x;
    int y;
    int r;
    int c;
    int v;
};
p po[20];
int ge=0;//part num
int n;
int res;
int l;
int cmp(const void * v1,const void * v2){
  if(((struct p *)v1)->y == ((struct p *)v2)->y)
    return ((struct p *)v1)->x -((struct p *)v2)->x;
  return ((struct p *)v1)->y - ((struct p *)v2)->y;
};


int trywalk(int i){
  if(po[i].v==1)
    return true;
  po[i].v=1;
  if(po[po[i].c].r==-1){
    po[i].v=-1;
    return false;
  }
  if(trywalk(po[po[i].c].r)){
    po[i].v=-1;
    return true;
  }else{
    po[i].v=-1;
    return false;
  }
}

void check(){
  int i;
  for(i=0;i<n;i++){
    if(trywalk(i)){
      res++;
      return ;
    }
  }
  return ;
};
void test(int i){
  int j;
  for(j=0;j<n;j++){
    if(i!=j && po[j].c==-1){
      po[i].c=j;
      po[j].c=i;
      l -= 2 ;
      if(l==0){
        check();
      }else{
        int k;
        for(k=0;k<n;k++){
          if(po[k].c==-1){
            test(k);
            break ;
           }
        }
      }
      l += 2 ;
      po[i].c=-1;
      po[j].c=-1;
    } 
  }
}

int main()
{
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin>>n;
    int i;
    //get
    for(i=0;i<n;i++){
      fin>>po[i].x>>po[i].y;
      po[i].c=po[i].v=-1;
    }
    //set
    qsort(po,n,sizeof(struct p),cmp);
    for(i=0;i<n;i++){
      if(i==n-1 || po[i].y!=po[i+1].y)
        po[i].r=-1;
      else
        po[i].r=i+1;
    }
    res =0;
    l = n ;
    test(0);
    fout<<res<<endl;
    
}
