/*
ID: 10157591
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
ifstream inc("heritage.in");
ofstream outc("heritage.out");

string inorder,preorder;

void trans(int startp,int endp,int starti,int endi){
  if(startp > endp)
    return;
  char ch = preorder[startp];
  int i;
  for(i=starti;i<=endi;i++){
    if(ch == inorder[i])
      break;
  }
  int lenleft = i-starti;
  trans(startp+1,startp+lenleft,starti,i-1);
  trans(startp+lenleft+1,endp,i+1,endi);
  outc<<ch;
}



int main(){
  inc>>inorder>>preorder;
  trans(0,preorder.length()-1,0,inorder.length()-1);
  outc<<endl;
  return 0;
}
