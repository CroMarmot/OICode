/*
ID: 10157591
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("fence.in");
ofstream outc("fence.out");
struct fen{
  int a;
  int b;
  int lefttimes;
};
struct li{
  int to;
  struct fen * f;
  struct li * next;
};
fen F[1034];
li l[510];
int cnt[510]={0};
int outputnum = 0;
int output[1034];
void appendli(int lindex,int t,fen * fe){
  li * ls = & l[lindex];
  while(!(ls->to <= t && (ls->next == NULL || ls->next->to > t)))
    ls = ls->next;
  if(ls->to == t){
    ls->f->lefttimes++;
    return ;
  }

  li * newli = new li;
  newli->next = ls->next;
  newli->f =fe;
  newli->to = t;
  ls->next = newli;
}
void ride(int i){
  li * ls =&l[i];
  while(ls->next != NULL){
    ls = ls->next;
    while(ls->f->lefttimes != 0){
      ls->f->lefttimes -= 2;
      ride(ls->to);
    }
  }
  output[outputnum++] = i;
}
int main(){
  int i;
  for(i=1;i<=500;i++){
    l[i].to = 0;
    l[i].next = NULL;
  }
  int n;
  inc>>n;
  for(i=0;i<n;i++){
    inc>>F[i].a>>F[i].b;
    F[i].lefttimes = 2;
    appendli(F[i].a,F[i].b, &F[i]);
    appendli(F[i].b,F[i].a, &F[i]);
    cnt[F[i].a]++;
    cnt[F[i].b]++;
  }
  int startpoint = 1;
  for(i=1;i<=500;i++){
    if(cnt[i] % 2){
      startpoint = i;
      break;
    }
  }
  ride(startpoint);
  for(i=outputnum-1;i>=0;i--)
    outc<<output[i]<<endl;
  return 0;
}
