/*
ID: 10157591
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int minn(int num1,int num2){
  return num1<num2?num1:num2;
}
int main(){
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
  int n;
  fin>>n;
  if(n<=5){
    fout<<n*n*n<<endl;
    return 0;
  }
  int a[3],b[3];
  fin>>a[0]>>a[1]>>a[2];
  fin>>b[0]>>b[1]>>b[2];

  int der[3];
  int i;
  for(i=0;i<3;i++){
    if(a[i]>b[i]){
      der[i]=5-minn(a[i]-b[i],(n+b[i]-a[i])%n);
    }else{
      der[i]=5-minn(b[i]-a[i],(n+a[i]-b[i])%n);
    }
    if(der[i]<0){
      der[i]=0;
    }
  }
 fout<<250-der[0]*der[1]*der[2]<<endl;
  return 0;
}
