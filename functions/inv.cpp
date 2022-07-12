#include<iostream>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)

namespace INV{
  // 1-index
  // [1->_arrlen]
  void init_arr(long long *_arr,int _arrlen,int _mod){
  _arr[1] = 1;
  rep(i,2,_arrlen+1)
    _arr[i] = ((_mod-_mod/i)*_arr[_mod%i])%_mod;
  }
}

long long inv[100000];

int main(){
  INV::init_arr(inv,1000,1'000'000'007);
  rep(i,0,100){
    cout<<i<<":"<<inv[i]<<endl;
  }
}
