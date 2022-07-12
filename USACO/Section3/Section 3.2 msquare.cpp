/*
ID: 10157591
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("msquare.in");
ofstream outc("msquare.out");

int visit[16434834/8] = {0}; // 0+8*(1+8*(2+8*(3+8*(4+8*(5+8*(6+8*(7))))))) + 10
int dest[8];

struct p{
  int g[8];
  int index;
  struct p * fa;
  struct p * next;
};

p * s, * e;

void init(){
  s = new p;
  s->index = -1;
  s->fa   = NULL;
  s->next = NULL;
  s->g[0]=1;
  s->g[1]=2;
  s->g[2]=3;
  s->g[3]=4;
  s->g[4]=5;
  s->g[5]=6;
  s->g[6]=7;
  s->g[7]=8;
  e = s;
}
void op0(p* f,p* t){
  t->g[0] = f->g[7];
  t->g[1] = f->g[6];
  t->g[2] = f->g[5];
  t->g[3] = f->g[4];
  t->g[4] = f->g[3];
  t->g[5] = f->g[2];
  t->g[6] = f->g[1];
  t->g[7] = f->g[0];
  t->fa    = f;
  t->index = 0;
}
void op1(p* f,p* t){
  t->g[0] = f->g[3];
  t->g[1] = f->g[0];
  t->g[2] = f->g[1];
  t->g[3] = f->g[2];
  t->g[4] = f->g[5];
  t->g[5] = f->g[6];
  t->g[6] = f->g[7];
  t->g[7] = f->g[4];
  t->fa    = f;
  t->index = 1;
}
void op2(p* f,p* t){
  t->g[0] = f->g[0];
  t->g[1] = f->g[6];
  t->g[2] = f->g[1];
  t->g[3] = f->g[3];
  t->g[4] = f->g[4];
  t->g[5] = f->g[2];
  t->g[6] = f->g[5];
  t->g[7] = f->g[7];
  t->fa    = f;
  t->index = 2;
}
bool checkUnvisited(p* pi){
  int i=
    pi->g[0]-1+8*(
      pi->g[1]-1+8*(
        pi->g[2]-1+8*(
          pi->g[3]-1+8*(
            pi->g[4]-1+8*(
              pi->g[5]-1+8*(
                pi->g[6]-1+8*(
                  pi->g[7]-1)))))));
  int j=i%8;
  if(!(visit[i/8] & (1<<j))){
    visit[i/8] |= (1<<j);
    return true;
  }
  return false;
}
bool check(p* pi){
  return
    pi->g[0] == dest[0] &&
    pi->g[1] == dest[1] &&
    pi->g[2] == dest[2] &&
    pi->g[3] == dest[3] &&
    pi->g[4] == dest[4] &&
    pi->g[5] == dest[5] &&
    pi->g[6] == dest[6] &&
    pi->g[7] == dest[7];
}
void backtrace(p* pi){
  int cnt=0;
  while(pi->fa!=NULL){
    cnt++;
    pi->fa->next=pi;
    pi=pi->fa;
  }
  outc<<cnt<<endl;
  pi = pi->next;
  while(pi!=NULL){
    outc<<char('A'+pi->index);
    pi=pi->next;
  }
  outc<<endl;
}

int main(){
  init();
  for(int i=0;i<8;i++)
    inc>>dest[i];
  if(check(s)){
    outc<<0<<endl<<endl;
    return 0;
  }
  checkUnvisited(s);
  typedef void (*funcp)(p* f,p* t);
  funcp func[3] = {op0,op1,op2};
  while(s!=NULL){
    p* ntmp;
    int j;
    for(j=0;j<3;j++){
      ntmp = new p;
      func[j](s,ntmp);
      if(check(ntmp)){
        backtrace(ntmp);
        return 0;
      }
      if(checkUnvisited(ntmp)){
        e->next = ntmp;
        e=e->next;
        e->next = NULL;
      }else{
        delete ntmp;
      }
    }
    s=s->next;
  }
  return 0;
}

