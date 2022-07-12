
/*
ID: 10157591
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
int res=0;
int hill[1010];
int minn(int num1,int num2){
  return num1<num2?num1:num2;
}
int main()
{
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int i,n;
    fin>>n;
    for(i=0;i<n;i++){
      fin>>hill[i];
      if(hill[i]>17){
        res+=(hill[i]-17)*(hill[i]-17);
      }
    }
    int j;
    for(j=1;j<=100-17;j++){
      int newres=0;
      for(i=0;i<n;i++){
        if(hill[i]<j){
          newres+=(hill[i]-j)*(hill[i]-j);
        }else if(hill[i]>j+17){
          newres+=(hill[i]-j-17)*(hill[i]-j-17);
        }
      }
      res= minn(res,newres);
    }
    fout<<res<<endl;
}
