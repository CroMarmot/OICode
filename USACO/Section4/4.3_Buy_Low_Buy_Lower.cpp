/*
ID: 10157591
PROG: buylow
LANG: C++
*/
#include <iostream>
#include <fstream>
#define MOD 100000000

using namespace std;
ifstream inc("buylow.in");
ofstream outc("buylow.out");

int maxx(int v1,int v2){
  return v1>v2?v1:v2;
}

struct bigint{
  int val[200];//log(10,2^5000) 5000/3/8 = 208
  int len;
  bigint(){
    val[0] = 0;
    len = 1;
  }
  const bigint operator +(const bigint &v2){
    bigint res;
    res.len = maxx(len,v2.len);
    int i;
    int jinwei = 0;
    for(i=0;i<res.len;i++){
      if(i >= len)
        res.val[i] = v2.val[i]+jinwei;
      else if(i >= v2.len)
        res.val[i] = val[i]+jinwei;
      else
        res.val[i] = val[i]+v2.val[i]+jinwei;
      jinwei = res.val[i] / MOD;
      res.val[i] %= MOD;
    }
    if(jinwei != 0){
      res.val[i] = jinwei;
      res.len ++ ;
    }
    return res;
  }
  friend ostream &operator<<(ostream &os,const bigint &v1){
    os<<v1.val[v1.len-1];
    int i;
    for(i=v1.len-2;i>=0;i--){
      if(     v1.val[i] >= 10000000)
        os<<v1.val[i];
      else if(v1.val[i] >=  1000000)
        os<<"0"<<v1.val[i];
      else if(v1.val[i] >=   100000)
        os<<"00"<<v1.val[i];
      else if(v1.val[i] >=    10000)
        os<<"000"<<v1.val[i];
      else if(v1.val[i] >=     1000)
        os<<"0000"<<v1.val[i];
      else if(v1.val[i] >=      100)
        os<<"00000"<<v1.val[i];
      else if(v1.val[i] >=       10)
        os<<"000000"<<v1.val[i];
      else
        os<<"0000000"<<v1.val[i];
    }
  }
  const void operator=(int n){
    len = 1;
    val[0] = n;
  }
  const void operator=(const bigint & v2){
    len = 0;
    while(len < v2.len){
      val[len] = v2.val[len];
      len++;
    }
  }
  void operator+=(const bigint &v2){
    *this=*this+v2;
  }
};

struct item{
  int v;
  int cnt;
  bigint typecnt;
};

item iii[5010];

void op(int index){
  int ans_i=0;
  int ans_cnt=1;
  bigint ans_typecnt;
  ans_typecnt = 0;
  int i;
  for(i=index-1;i>0;i--){
    if(iii[i].v > iii[index].v){
      if(ans_cnt < iii[i].cnt + 1){
        ans_cnt = iii[i].cnt+1;
        ans_i   = i;
        ans_typecnt = iii[i].typecnt;
      }else if(ans_cnt == iii[i].cnt + 1){
        ans_typecnt += iii[i].typecnt;
      }
    }else if(iii[i].v == iii[index].v){
      break;
    }
  }
  if(ans_i != 0){
    iii[index].cnt = ans_cnt;
    iii[index].typecnt = ans_typecnt;
  }else if(i == 0){
    iii[index].cnt = 1;
    iii[index].typecnt = 1;
  }
}

int main(){
  int n,i;
  inc>>n;
  for(i=1;i<=n;i++){
    inc>>iii[i].v;
    iii[i].cnt = 0;
    iii[i].typecnt = 0;
  }
  iii[1].cnt = 1;
  iii[1].typecnt = 1;
  for(i=2;i<=n;i++){
    op(i);
  }
  int ans_cnt = 1;
  int ans_i = 1;
  bigint ans_typecnt;
  ans_typecnt = 0;
  for(i=1;i<=n;i++){
    if(ans_cnt < iii[i].cnt){
      ans_cnt = iii[i].cnt;
      ans_i = i;
      ans_typecnt = iii[i].typecnt;
    }else if(ans_cnt == iii[i].cnt){
      ans_typecnt += iii[i].typecnt;
    }
  }
  outc<<ans_cnt<<" ";
  outc<<ans_typecnt;
  outc<<endl;;
  return 0;
}
