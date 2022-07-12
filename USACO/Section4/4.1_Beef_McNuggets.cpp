/*
ID: 10157591
PROG: nuggets
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("nuggets.in");
ofstream outc("nuggets.out");

int n;
int num[20];

int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}

int minn(int v1,int v2){
  return v1<v2?v1:v2;
}

void iiii(int val){
  int res = val==-1?0:val;
  outc<<res<<endl;
}

int main(){
  int i,j;
  int resgcd=0;
  int avaliable[600]={0};
  int * thisarr, * nextarr;
  inc>>n;
  for(i=0;i<n;i++){
    inc>>num[i];
    resgcd = gcd(resgcd,num[i]);
  }
  int gap = num[0];
  for(i=1;i<n;i++)
    gap = minn(gap,num[i]);

  if(resgcd!=1){
    iiii(-1);
    return 0;
  }

  // if(n==2 && gcd(num[0],num[1])){
  //   iiii(num[0]*num[1]-num[0]-num[1]);
  //   return 0;
  // }

  int lastinvalid = 0;
  int base = 0;
  thisarr = avaliable;
  nextarr = &avaliable[256];
  thisarr[0] = 1;
  while(1){
    for(i=0;i<256;i++){
      if(thisarr[i]){
        if(i+base-lastinvalid >= gap){
          iiii(lastinvalid);
          return 0;
        }
        for(j=0;j<n;j++){
          int der = num[j];
          thisarr[i+der] = 1;
        }
      }else{
        lastinvalid = base + i;
      }
    }
    base+=256;
    for(i=0;i<256;i++){
      thisarr[i] = nextarr[i];
      nextarr[i] = 0;
    }
  }
  iiii(-1);
  return 0;
}

/*
 * if gcd(p,q) = 1,then the min value which can't be cacluate by n*p+m*q (n>=0,m>=0) is (p-1)(q-1)-1
 *
 * at first there are no a and b
 *         a*p+b*q = (p-1)(q-1)-1
 * (a+1)*p+(b+1)*q = pq
 * q | a+1
 * p | b+1
 * a>=0,b>=0
 * left >= 2pq > pq
 *
 * divide all number to q groups {0(mod q)},{1(mod q)}.. {q-1(mod q)}
 * if a value xi in {i(mod q)} is avaliable then xi+q is also avaliable
 *
 * because gcd(p,q)=1,so
 *
 * {1*p,2*p,3*p..(q-1)*p} is one on one mapping to such groups and these value are avaliable
 *
 * so the max unavaliable value in each groups is lessequal than {1*p-q,2*p-q,3*p-q,....(q-1)*p-q}
 *
 * so in total p*q-q-p is both the maxpossible unavaliable value and the unavaliable value.
 *
 * what should be notice is the above conclusion is based on gcd(p,q)=1
 *
 * -----
 *
 * for this problem, I assume gcd(a,b)!=1;
 *
 * relate:http://mathworld.wolfram.com/CoinProblem.html
 *
 * According to this page this conclusion seems to have not yet been proved
 *
 * -----
 *
 * code method:
 *
 * if(i~i+minvalue is avaliable) then the result < i , and the maxvalue < 256, use array[256] circulation
 *
 * */
