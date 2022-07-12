/**
 * @author      : cromarmot (yexiaorain@gmail.com)
 * @license     : GPL
 * @created     : 星期三 6月 03, 2020 11:13:14 CST
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ten5 100000+10
#define MOD 1000000007
#define rep(i,a,n) for (uint i=a;i<n;i++)
#define iif(c,t,f) ((c)?(t):(f))
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);

const uint N = 1'000'000;

uint next_value(uint value,uint *fac) {
    uint sum = 0;
    while(value != 0){
        sum += fac[value%10];
        value/=10;
    }
    return sum;
}

pair<uint,uint> dfs(
    uint *fac,
    unordered_map<uint,uint> &ans,
    unordered_map<uint,uint> dep,
    uint value
    ) { // dep, len
    uint nv = next_value(value,fac);
    uint next_dep = dep[value] + 1;
    if(dep.count(nv)){
      auto rs = dep[nv];
      // printf("%d => %d\n",value,next_dep - rs);
      ans[value] = next_dep - rs;
      return {rs,next_dep - rs};
    }else {
      if(ans.count(nv)) {
        auto res = ans[nv];
        auto newres= res + 1;
        // printf("%d => %d\n",value,newres);
        ans[value] = newres;
        return {next_dep,newres};
      }else{
        dep[nv] = next_dep;
        auto ret = dfs(fac,ans,dep,nv);
        if(next_dep <= ret.first){
          ret.second += 1;
        }
        // printf("%d => %d\n",value,ret.second);
        ans[value] = ret.second;
        return ret;
      }
    }
}

int main() {
    uint fac[11];
    unordered_map<uint,uint> ans;
    fac[0] = 1;
    rep(i,1,11){
        fac[i] = fac[i-1]*i;
    }
    rep(i,1,N+1){
        if(ans.count(i)){
            continue;
        }
        unordered_map<uint,uint> dep;
        dep[i] = 0;
        dfs(fac,ans,dep,i);
    }
    auto cnt = 0;
    for (auto [k,v]: ans) {
        if( v >= 60 && k <= N ){
            cnt+=1;
            // println!("{}: \"{}\"", k, v);
        }
    }
    printf("%d",cnt);
    return 0;
}

