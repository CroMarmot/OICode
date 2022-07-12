#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,a,n) for (ll i=(n)-1;i>a;i--)
#define pb push_back

const int MAXV = 3010;
const int MAXE = 200010;
const int INF = 0x3f3f3f3f;

struct edge{
    int u,v,w,next;
}e[MAXE];

int head[MAXV]; // 每个边的 链的头 只存原始相连的，不存合并后的, 末端-1
int edge_num;

void insert_edge(int u,int v,int w){
    e[edge_num] = {u,v,w,head[u]};
    head[u]=edge_num++;
}

int fa[MAXV]; // 并查集, 保证和link块的头是一致的 但更快速
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int link[MAXV]; // 链表来合并并查集 单复杂度O(n), 总复杂度O(n^2) 末端-1,

// 每轮phase内部不会合并link，每轮phase结束以后会合并link

int N,M;

// 每轮PHASE
int val[MAXV]; // 每个并查集块和 头部并查集块的距离，配合优先队列，找最大的距离
bool vis[MAXV];

void merge(int u,int v){
    int p=u;
    while(~link[p])p=link[p];
    link[p]=v;
    fa[v]=u;
}

int Phase(int cnt,int &s,int &t){
    memset(val,0,sizeof(val));
    memset(vis,0,sizeof(vis));
    // priority_queue 大的靠前，pair先比first后比second，
    priority_queue<pair<int,int> > que; // {weight, head}

    t = 1;
    while(--cnt){
        s = t; // 本PHASE内，上一次合并进来的link块头
        // 是否合并
        vis[s]=true;
        for(int u=s;~u;u=link[u]){
            // u 是历史轮次已经合并的点
            for(int p=head[u];~p;p=e[p].next){
                // 把t和剩余所有做切割
                int v=find(e[p].v);
                // 本轮Phase未合并
                if(!vis[v]){
                    // 这里不会重复加边权，每一轮while对应link内的点, 都是互相没有重复的
                    que.push({val[v]+=e[p].w,v});
                }
            }
        }
        t=0;
        while(!t){
            if(que.empty())return 0;
            pair<int,int> tp=que.top();
            que.pop();
            // 省去了去重和移除老的，保证了大的在头
            // 但是这里的que，整个while都在用，即使移去了每次最大，依然还是需要 == 来判定 是否是当前轮次 可合并的
            // 例如第一轮加入了 {w0,v},{w1,v} 移去了{w1,v}可能剩下{w0,v}在第二轮
            if(val[tp.second]==tp.first){
                t=tp.second;
            }
        }
    }
    return val[t];
}

int StoerWagner(){
    int res=INF;
    per(i,1,N+1){
        int s,t;
        res=min(res,Phase(i,s,t));
        if(res==0)break;
        merge(s,t);
    }
    return res;
}

int main() {
    int a;
    while(~scanf("%d%d",&N,&M)){
        memset(head,-1,sizeof(head));
        memset(link,-1,sizeof(link));
        rep(i,1,N+1){
            fa[i]=i;
        }
        edge_num=0;
        int u,v,w;
        rep(i,0,M){
            scanf("%d%d%d",&u,&v,&w);
            insert_edge(u,v,w);
            insert_edge(v,u,w);
        }
        printf("%d\n",StoerWagner());
    }
    return 0;
}

// 临接 表
// O(n m log(m) )
//
// In:
// 2 1
// 1 2 1
// 3 3
// 1 2 5
// 1 2 4
// 2 3 3
// Out
// 1
// 3
