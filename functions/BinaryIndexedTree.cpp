#include<iostream>

const int bitnum = 1000000;
// 1 <= _index <= bitnum
long long bittree[bitnum+10];


namespace BITTREE{
  // 1-index,
  int lowbit(int v){
    return v&(-v);
  }

  void bitclear(long long * arr,int _n){
    for(int i = 0; i <= _n; i++)
      arr[i] = 0;
  }

  // 最大限度_n, 下标_index 变化为_val
  void bitadd(long long * arr, int _n, int _index, long long _val){
    for(;_index <= _n;_index += lowbit(_index))
      arr[_index] += _val;
  }
  // [1->_index]的和
  long long bitquery(long long *arr, int _index){
    long long ret = 0;
    for(;_index != 0;_index^=lowbit(_index))
      ret += arr[_index];
    return ret;
  }
}

int main(){
  for(int i=1;i<8;i++){
    // [i]+=i;
    BITTREE::bitadd(bittree,bitnum,i,i);
  }
  for(int i=1;i<8;i++){
    printf("%d:%lld\n",i,BITTREE::bitquery(bittree,i));
  }

}
