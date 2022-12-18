#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 最小费用 最大流模版.求最大费用最大流建图时把费用取负即可。
// 无向边转换成有向边时需要拆分成两条有向边。即两次加边。
template<typename T, T INF>
class MinCostMaxFlow{
  public:
    struct Edge {
      int u;
      int v;
      T cap;
      T cost;
    };
    int n ; // 点 1-index
    vector<Edge> e; // e = {u,v,cap,cost}
    int eidx = 0;
    vector<vector<pair<int,int> > > u2ve;
    vector<T> dis;
    vector<int> pre;

    MinCostMaxFlow(int n):n(n){ u2ve.resize(n); } // 0-index
    void edge(int u,int v,T cap,T cost) {
      u2ve[u].push_back({v,e.size()});
      e.push_back(Edge{u,v,cap,cost});
      u2ve[v].push_back({u,e.size()});
      e.push_back(Edge{v,u,0,-cost});
    }
    bool spfa(int s,int t) {
      queue<int> q;
      vector<bool> vis(n,false); // 是否在queue中
      pre = vector<int>(n,-1); // 前向 边id
      dis = vector<T>(n,INF); // 距离 = 单位cost之和!!! TODO 不要yong magic number, 增加一个变量记录
      vis[s] = true;
      dis[s] = 0;
      q.push(s);
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(auto [v,ei]:u2ve[u]){
          if(e[ei].cap && dis[v] > dis[u] + e[ei].cost) { // 这里实现了最小, 不能有负环
            dis[v] = dis[u] + e[ei].cost;
            pre[v] = ei;
            if(!vis[v]) {
              q.push(v);
              vis[v]=true;
            }
          }
        }
      }
      return dis[t] != INF;
    }

    // return {最小费用,最大流}
    pair<T,T> flow(int s,int t) {
      T flow = 0; // 总流量
      T mincost = 0;
      while(spfa(s,t)) {
        T minflow = INF;
        for(int ei=pre[t];ei!=-1;ei=pre[e[ei].u]){
          if(e[ei].cap < minflow) minflow = e[ei].cap;
        }
        flow += minflow;
        for(int ei=pre[t];ei!=-1;ei=pre[e[ei].u]) {
          e[ei].cap -= minflow;
          e[ei^1].cap += minflow;
        }
        mincost += dis[t] * minflow;
      }
      return {mincost,flow}; // 最大流
    }
    pair<T,T> getEdgeFlowCap(int edgeid){ // follow the add order, return {flow, cap}
      assert(edgeid*2 < (int)e.size());
      return {e[edgeid*2+1].cap, e[edgeid*2].cap+e[edgeid*2+1].cap };
    }
};

template<typename T, T INF>
class MinCostFlow{
  public:
    struct Edge {
      int u;
      int v;
      T cap;
      T cost;
    };
    int n ; // 点 1-index
    vector<Edge> e; // e = {u,v,cap,cost}
    int eidx = 0;
    vector<vector<pair<int,int> > > u2ve;
    vector<T> dis;
    vector<int> pre;

    MinCostFlow(int n):n(n){ u2ve.resize(n); } // 0-index
    void edge(int u,int v,T cap,T cost) {
      u2ve[u].push_back({v,e.size()});
      e.push_back(Edge{u,v,cap,cost});
      u2ve[v].push_back({u,e.size()});
      e.push_back(Edge{v,u,0,-cost});
    }
    bool spfa(int s,int t) {
      queue<int> q;
      vector<bool> in_queue(n,false); // 是否在queue中
      pre = vector<int>(n,-1); // 前向 边id
      dis = vector<T>(n,INF); // 距离 = 单位cost之和!!! TODO 不要yong magic number, 增加一个变量记录
      in_queue[s] = true;
      dis[s] = 0;
      q.push(s);
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for(auto [v,ei]:u2ve[u]){
          if(e[ei].cap && dis[v] > dis[u] + e[ei].cost) { // 这里实现了最小, 不能有负环
            dis[v] = dis[u] + e[ei].cost;
            pre[v] = ei;
            if(!in_queue[v]) {
              q.push(v);
              in_queue[v]=true;
            }
          }
        }
      }
      return dis[t] != INF and dis[t] < 0; // min cost ignore >= 0 cost
    }

    // return {最小费用,最大流}
    pair<T,T> flow(int s,int t) {
      T flow = 0; // 总流量
      T mincost = 0;
      while(spfa(s,t)) {
        T minflow = INF;
        for(int ei=pre[t];ei!=-1;ei=pre[e[ei].u]){
          if(e[ei].cap < minflow) minflow = e[ei].cap;
        }
        flow += minflow;
        for(int ei=pre[t];ei!=-1;ei=pre[e[ei].u]) {
          e[ei].cap -= minflow;
          e[ei^1].cap += minflow;
        }
        mincost += dis[t] * minflow;
      }
      return {mincost,flow}; // 最大流
    }
    pair<T,T> getEdgeFlowCap(int edgeid){ // follow the add order, return {flow, cap}
      assert(edgeid*2 < (int)e.size());
      return {e[edgeid*2+1].cap, e[edgeid*2].cap+e[edgeid*2+1].cap };
    }
};


int main(){
  // const int INF = 0x3f3f3f3f;
  const ll INF = 0x3f3f3f3f3f3f3f3f;
  {
    // 求最小cost
    MinCostMaxFlow <ll,INF>g(4/*点个数*/);
    g.edge(0,1,5,1); // 1 -> 2, 容量5, 单价1
    g.edge(0,2,3,3); // 1 -> 3, 容量3, 单价3
    g.edge(1,2,3,1); // 2 -> 3, 容量3, 单价1
    g.edge(2,3,4,0); // 3 -> 4, 容量4, 单价0
    auto [mincost,maxflow] = g.flow(0,3);
    printf("mincost %lld, maxflow %lld\n",mincost,maxflow);
  }
  { // 求最大cost 全部取负
    MinCostMaxFlow <ll,INF>g(4/*点个数*/);
    g.edge(0,1,5,-1); // 1 -> 2, 容量5, 单价1
    g.edge(0,2,3,-3); // 1 -> 3, 容量3, 单价3
    g.edge(1,2,3,-1); // 2 -> 3, 容量3, 单价1
    g.edge(2,3,4,0); // 3 -> 4, 容量4, 单价0
    auto [mincost,maxflow] = g.flow(0,3);
    printf("mincost %lld, maxflow %lld\n",mincost,maxflow);
  }
  return 0;
}
