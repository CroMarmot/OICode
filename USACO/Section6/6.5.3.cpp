/*
ID: 10157591
PROG: betsy
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "betsy";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;

// 中间的 每个块 连接 两个方向，

map<pair<int,long long>,long long> res;

int get_state(long long state,int pos){
  return (state >> (2*pos)) % 4;
}

int set_state(long long state,int pos){
  return state << (2*pos);
}

// ((    ) ())
//   1
//  4 2
//   3
long long insert_state(long long old_state,int pos,int block){
  int arr[10];
  // 栈计算括号对
  int p[10];
  int stk[10];
  int stki = 0;
  rep(i,0,n+1){
    arr[i] = get_state(old_state,i);
    if(arr[i] == 0)continue;
    if(arr[i] == 1)stk[stki++]=i;
    if(arr[i] == 2){
      p[i] = stk[stki-1];
      p[stk[stki-1]] = i;
      stki--;
    }
  }
  int cnt = 0;
  rep(i,0,4){
    cnt+= !!(block & (1<<i));
  }
  assert(cnt == 2);
  // 插入的块和 被插入的位置 同时有或没有
  if( (!(block & 0b1000) != !arr[pos]) || (!(block & 0b0001) != !arr[pos+1]) ){
    return -1;
  }
  // 原来为空 新建边
  if( (block & 0b0100) && (block & 0b0010)){
    arr[pos] = 1;
    arr[pos+1] = 2;
  }else if( (block & 0b0100) || (block & 0b0010) ){ // 引出一条原来的边
    if(block & 0b0100){
      arr[pos] = arr[pos]+arr[pos+1];
      arr[pos+1] = 0;
    }else {
      arr[pos+1] = arr[pos]+arr[pos+1];
      arr[pos] = 0;
    }
  }else{ // 把原来两段 连接起来
    if(arr[pos] == 1 &&  arr[pos+1] == 2){
      arr[pos] = 0 ;
      arr[pos+1] = 0 ;
    }else{
      arr[pos] = 0;
      arr[pos+1] = 0;
      int p1 = p[pos];
      int p2 = p[pos+1];
      if(p1 > p2)swap(p1,p2);
      arr[p1] = 1;
      arr[p2] = 2;
    }
  }
  long long new_state = 0;
  rep(i,0,n+1){
    new_state += set_state(arr[i],i);
  }
  return new_state;
}

long long dp(int idxi,int idxj,long long state){
  long long &ret = res[{(idxi<<3)+idxj,state}];
  if(ret != 0){
    return ret;
  }
    // 右下角允许自连
  if(idxj == n-1 && idxi == n-1) {
    return ret = (get_state(state,n-1) == 1 && get_state(state,n) == 2);
  }
  // 过程中不允许自连
  //
  if (get_state(state,idxi) == 1 && get_state(state,idxi+1) == 2)return 0;
  rep(i,0,4){
    rep(j,i+1,4){
      int new_state = insert_state(state,idxi,(1<<i)+(1<<j));
      if(new_state == -1)continue;
      // 最后一列
      if(idxj == n-1) {
        if(get_state(new_state,idxi) != 0)continue;
      }
      // 最后一行
      if(idxi == n-1){
        if(get_state(new_state,idxi+1) != 0)continue;
        new_state <<=2;
        ret+=dp(0,idxj+1,new_state);
      }else{
        ret+=dp(idxi+1,idxj,new_state);
      }
    }
  }
  // printf("(%d,%d) {%lld,%lld,%lld} = %lld\n",idxi,idxj,(state)%4,(state>>2)%4,(state>>4)%4,ret);
  return ret;
}

int main(){
  usefile();
  cin>>n;
  if(n == 1){
    cout<<1<<endl;
  }else{
    cout<<dp(0,0,set_state(1,1)+set_state(2,n))<<endl;
  }
  return 0;
}
