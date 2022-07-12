#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair

int intcmp(const void *v1,const void *v2){return *(int *)v1-*(int *)v2;}

char t[1000010];

#define ARRHASESIZE 1000000
class arrhash{
  private:
    ll b;
    ll m;
    ll bp[ARRHASESIZE+10];
    ll th[ARRHASESIZE+10];
  public:
    arrhash(ll base,ll mod):b(base),m(mod){
    };
    void init(int len,ll (*oriv)(int pos)){
      bp[0]=1;
      rep(i,0,len){
        bp[i+1] = (bp[i]*b)%m;
        th[i+1] = (th[i]*b+t[i])%m;
      }
    }
    ll gethash(int l,int r){ // [0,1,2,3,4] -> gethash(0,5) -> [idx,idx+len]
      return ((th[r]-th[l]*bp[r-l])%m+m)%m;
    }
};

ll reti(int idx){
  return ll(t[idx]);
}
arrhash ah = arrhash(211,MOD);

int main(){
  scanf("%s",t);
  ah.init(strlen(t),&reti);
  ll hash = ah.gethash(2,2+3);
  cout<<hash<<endl;
  return 0;
}
