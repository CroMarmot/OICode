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
  rank = vector<int>(n);
  sa = vector<int>(n);
  iota(sa.begin(),sa.end(),0);
  rep(i,0,n) rank[i]=arr[i];
  for(int w=1; w<=2*n; w*=2) {
    vector<pair<int,int>>val;
    rep(i,0,n)val.push_back({rank[i],i+w/2<n?rank[i+w/2]:-1});
    sort(sa.begin(),sa.end(), [&](int i,int j){ return val[i]<val[j]; });
    rank[sa[0]] = 0;
    rep(i,1,n) rank[sa[i]] = rank[sa[i-1]] + (val[sa[i]]!=val[sa[i-1]]);
  }
  // height
  h = vector<int>(n);
  int k = 0;
  rep(i,0,n) {
    if (rank[i] == 0) continue;
    if (k) --k;
    while (arr[i + k] == arr[sa[rank[i] - 1] + k]) ++k;
    h[rank[i]] = k;
  }
}

void auto_test() {
  char s[100] = "aabaaaab";
  int n = strlen(s) ;
  printf("s:%s\n",s);
  vector<char> arr ;
  rep(i,0,n) arr.push_back(s[i]);
  vector<int> sa;
  vector<int> rank;
  vector<int> h;
  calc_sa_rank(arr, sa, rank, h);
  assert(sa==(vector<int>{3,4,5,0,6,1,7,2}));
  assert(rank==(vector<int>{3,5,7,0,1,2,4,6}));
  assert(h==(vector<int>{0,3,2,3,1,2,0,1}));
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
  auto_test();
  return 0;
}
