/*
ID: 10157591
PROG: prime3
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (long long i=a;i<n;i++)
#define per(i,a,n) for (long long i=n-1;i>=a;i--)

using namespace std;

const string filename = "prime3";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int A[10][10];
int p[100010];
vector<int>sum2v[100010];
set<string>ss;
int s;

void print(){
  string news = "";
  rep(i,0,5){
    rep(j,0,5){
      news += ('0'+A[i][j]);
    }
    news += '\n';
  }
  ss.insert(news);
  return ;
  static bool pre_n = false;
  if(pre_n){
    printf("\n");
  }else{
    pre_n = true;
  }
  rep(i,0,5){
    rep(j,0,5){
      printf("%d",A[i][j]);
    }
    printf("\n");
  }
}

void check(){
  int ncnt = 0;
  int sum = 0;
  per(i,0,5){
    sum*=10;
    sum+=A[i][4-i];
    ncnt+=A[i][4-i];
  }
  if(ncnt != s)return;
  if(p[sum])return;
  int sum0=0;
  int ncnt0=0;
  rep(i,0,4){
    sum0+=A[i][i];
    sum0*=10;
    ncnt0+=A[i][i];
  }
  int sum1=0;
  int ncnt1=0;
  rep(j,0,4){
    sum1+=A[4][j];
    sum1*=10;
    ncnt1+=A[4][j];
  }
  int sum2=0;
  int ncnt2=0;
  rep(i,0,4){
    sum2+=A[i][4];
    sum2*=10;
    ncnt2+=A[i][4];
  }
  if(ncnt0 != ncnt1 || ncnt0 != ncnt2)return;
  int i = s - ncnt0;
  if(i < 0 || i > 10 || i%2 == 0)return ;
  if((!p[sum0+i]) && (!p[sum1+i]) && (!p[sum2+i])){
    // printf("sum:%d\n",sum);
    A[4][4] = i;
    print();
  }
}

void dfs(int ij){
  if(ij == 4){
    check();
    return ;
  }
  int prerow = 0;
  int precol = 0;
  rep(j,0,ij){
    prerow *=10;
    prerow += A[ij][j];
  }
  if(ij == 0){
    prerow = A[0][0];
  }

  rep(i,0,ij){
    precol += A[i][ij];
    precol *=10;
  }

  // A[2][2]
  if(ij == 2){
    int mid = s- A[4][0]-A[3][1]-A[1][3]-A[0][4];
    if(mid < 0 || mid > 9)return;
    int v = A[4][0]*10000+A[3][1]*1000+mid*100+A[1][3]*10+A[0][4];
    if(p[v])return;// 左下到右上
    prerow = prerow*10+mid;
  }

  for(auto vrow:sum2v[prerow]){
    int pre0 = false;
    per(j,0,5){
      A[ij][j]=vrow%10;
      vrow/=10;
      if(ij == 0 && A[ij][j] == 0){
        pre0 = true;
        break;
      }
    }
    if(pre0)continue;
    int pcol = precol+A[ij][ij];
    for(auto vcol:sum2v[pcol]){
      pre0 = false;
      per(i,0,5){
        A[i][ij]=vcol%10;
        vcol/=10;
        if(ij == 0 && A[i][ij] == 0){
          pre0 = true;
          break;
        }
      }
      if(pre0)continue;
      dfs(ij+1);
    }
  }
}

void init(){
  rep(i,2,100000){
    if(!p[i]){
      if(i>=10000){
        int sum = 0;
        int ii = i;
        rep(idx,0,5){
          sum+=ii%10;
          ii/=10;
        }
        if(sum == s){
          int ii = i;
          rep(idx,0,5){
            sum2v[ii].push_back(i);
            ii/=10;
          }
        }
      }
      for(long long j = i*i;j<100000;j+=i){
        p[j] = 1;
      }
    }
  }
}

int main(){
  usefile();
  cin>>s>>A[0][0];
  init();
  dfs(0);
  for(auto item:ss){
    static bool pn = false;
    if(pn){
      printf("\n");
    }else{
      pn = true;
    }
    printf("%s",item.c_str());
  }
  return 0;
}
