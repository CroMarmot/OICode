#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc314/submissions/49588250
int main(){
  using real = double;
  using segment_type = tuple<real, real, real, real>;
  using point_type = tuple<real, real>;
  vector<segment_type> segments;
  // 两点
  const auto distance_point_and_point{[](const point_type &point0, const point_type &point1) {
    const auto&[x0, y0]{point0};
    const auto&[x1, y1]{point1};
    return hypot(x0 - x1, y0 - y1); // 平方和的平方根
  }};
  // 点 到线段
  const auto distance_segment_and_point{[&](const segment_type &segment, const point_type &point) {
    const auto&[x0, y0, x1, y1]{segment};
    const auto&[x, y]{point};
    if ((x0 - x1) * (x0 - x) + (y0 - y1) * (y0 - y) < 0) // 角 (x1,y1)-(x0,y0)-(x,y) 是否是钝角
      return distance_point_and_point({x0, y0}, {x, y}); // 离 (x0,y0) 最近
    if ((x1 - x0) * (x1 - x) + (y1 - y0) * (y1 - y) < 0) // 角 (x0,y0)-(x1,y1)-(x,y) 是否是钝角
      return distance_point_and_point({x1, y1}, {x, y}); // 离 (x1,y1) 最近
    // 垂点在 (x0,y0,x1,y1)之间, = (x1-x0,y1-y0) x (x-x0,y-y0) / len((x1-x0,y1-y0))
    return abs((x0 - x1) * (y0 - y) - (y0 - y1) * (x0 - x)) / distance_point_and_point({x0, y0}, {x1, y1});
  }};
  return 0;
}


