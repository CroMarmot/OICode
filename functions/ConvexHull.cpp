#include <bits/stdc++.h>

template<class T>
using Point = std::pair<T, T>;

template<class T>
class ConvexHull{
public:
  std::vector<Point<T>> lower;
  std::vector<Point<T>> upper;
  Point<T> sub(Point<T> a,Point<T> b){ // return a-b
    return {a.first - b.first,a.second-b.second};
  }
  T cross(Point<T> a, Point<T> b, Point<T> c){ // (a-b) x (c-b)
    auto [x0,y0] = sub(a,b);
    auto [x1,y1] = sub(c,b);
    return x1*y0 -x0*y1;
  }
  ConvexHull(): lower{}, upper{}{}
  ConvexHull(Point<T> p): lower{p}, upper{p}{}
  ConvexHull(std::vector<Point<T>>&p) {
    sort(p.begin(),p.end());
    {
      std::vector<Point<T>> v=p; // 逆时针弧
      for(Point<T>p : v){
        while(lower.size() >= 2 && cross(lower.rbegin()[1], lower.back(), p) <= 0) lower.pop_back();
        lower.push_back(p);
      }
    }
    {
      std::vector<Point<T>> v=p; // 顺时针弧
      for(Point<T>p : v){
        while(upper.size() >= 2 && cross(upper.rbegin()[1], upper.back(), p) >= 0) upper.pop_back();
        upper.push_back(p);
      }
    }
  }
  ConvexHull(const ConvexHull& a, const ConvexHull& b){ // 两个凸包合并
    {
      std::vector<Point<T>> v; // 逆时针弧
      std::merge(a.lower.begin(), a.lower.end(), b.lower.begin(), b.lower.end(), back_inserter(v)); // 本身a,b下标有序, merge 会按pair的比较的排序
      for(Point p : v){
        while(lower.size() >= 2 && cross(lower.rbegin()[1], lower.back(), p) <= 0) lower.pop_back();
        lower.push_back(p);
      }
    }
    {
      std::vector<Point<T>> v; // 顺时针弧
      std::merge(a.upper.begin(), a.upper.end(), b.upper.begin(), b.upper.end(), back_inserter(v)); // 本身a,b下标有序, merge 会按pair的比较的排序
      for(Point p : v){
        while(upper.size() >= 2 && cross(upper.rbegin()[1], upper.back(), p) >= 0) upper.pop_back();
        upper.push_back(p);
      }
    }
  }
};


int main(){
  using ll=long long;
  auto read=[](){ll v;std::cin>>v;return v;};
  ll Q = read(); // 2e5
  std::vector<ConvexHull<ll>> S;
  for(ll i=1;i<=Q;i++){
    ll X = read();
    ll Y = read(); // + (X,Y)
    S.emplace_back(std::pair{X, Y});
    // 最低位 2的幂次 次处理, 其实就是树状数组的想法, 每个位置表示 二进制最低位对应的一断内容,现在直接收集起来
    for(int j = i; j%2==0; j/=2){
      S.rbegin()[1] = ConvexHull(S.rbegin()[1], S.back());
      S.pop_back();
    }
    ll ans = -0x3f3f3f3f3f3f3f3f;
    printf("%lld\n",ans);
  }
  return 0;
}


