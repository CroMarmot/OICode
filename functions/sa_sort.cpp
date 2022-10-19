#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (ll i=a;i<n;i++)

// 0-index + vector + sort
// sa 下标按照顺序排列
// rank 下标对应顺序index
// h sa 中相邻后缀 最长公共前缀 h[0] = 0; h[i] = 最长公共前缀(s[sa[i]..],s[sa[i-1]..])
template<class T>
void calc_sa_rank(vector<T>& arr, vector<int> &sa,vector<int> &rank, vector<int>&h){
  int n = arr.size();
  rank = vector<int>(n,0);
  sa = vector<int>(n,0);
  iota(sa.begin(),sa.end(), 0);
  sort(sa.begin(),sa.end(), [=](int i,int j){return arr[i] < arr[j];});
  rep(i,1,n) rank[sa[i]] = rank[sa[i-1]] + !(arr[sa[i]] == arr[sa[i-1]]);
  for(int w = 1; w < n; w *= 2) {
    auto rank0 = rank;
    auto rk = [=](int i){return i < n ? rank0[i] : -1;};
    sort(sa.begin(),sa.end(), [=](int i,int j){
        return rk(i) != rk(j) ? rk(i) < rk(j) : rk(i+w) < rk(j+w);
    });
    rank[sa[0]] = 0;
    rep(i,1,n) rank[sa[i]] = rank[sa[i-1]] + !(rk(sa[i]) == rk(sa[i-1]) && rk(sa[i]+w) == rk(sa[i-1]+w));
  }
  // height
  h = vector<int>(n,0);
  int k = 0;
  rep(i,0,n) {
    if (rank[i] == 0) continue;
    if (k) --k;
    while (arr[i + k] == arr[sa[rank[i] - 1] + k]) ++k;
    h[rank[i]] = k;
  }
}


int main() {
  char s[100] = "aabaaaab";
  int n = strlen(s) ;
  printf("s:%s\n",s);
  vector<char> arr ;
  rep(i,0,n) arr.push_back(s[i]);
  vector<int> sa;
  vector<int> rank;
  vector<int> h;
  calc_sa_rank(arr, sa, rank, h);
  printf("sa:\n");
  rep(i,0,n) printf("%d %s\n", sa[i], s + sa[i]);
  printf("\nrk:\n");
  rep(i,0,n) printf("%d %s\n", rank[i], s + i);
  printf("\nhei:");
  rep(i,0,n) printf("%d ", h[i]);
  printf("\n");
  return 0;
}
