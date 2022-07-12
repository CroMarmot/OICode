#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class INV{
  private:
  int *inv;
  public:
    int get(int i){
      return inv[i];
    }
    INV(int maxv,int p){
      assert(maxv >= 1);
      assert(maxv < p); // inv[v] = inv[v%p]
      inv = new int[maxv+1];
      inv[1] = 1;
      for(int i=2;i<=maxv;i++)
        inv[i] = ((p-p/i)*inv[p%i])%p;
    }
    ~INV(){
      delete [] inv;
    }
};

int main(){
  INV inv(100,MOD);
  cout<<inv.get(2)<<endl;
}
