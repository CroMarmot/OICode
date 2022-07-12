/*
ID: 10157591
PROG: cowxor
LANG: C++
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)

using namespace std;

const string filename = "cowxor";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int n;
int a[100010];
int p[100010];
int ns[500010][2];

int nsi=0;

int *root = ns[nsi++];

map<int,vector<int> > pv2idx; // 前缀异或 到 下表

void build(int idx){
  int v = p[idx];
  pv2idx[v].push_back(idx); // ordered
  int * po = root;
  per(i,1,21){
    int bit = !!(v&(1<<i));
    if(!po[bit]){
      po[bit] = nsi++;
    }
    po=ns[po[bit]];
  }
  int bit = !!(v&1);
  po[bit] = v;
}

int query(int idx){
  int v = p[idx];
  int * po = root;
  per(i,1,21){
    int bit = !(v&(1<<i));
    if(!po[bit]){
      po = ns[po[bit^1]];
    }else{
      po = ns[po[bit]];
    }
  }
  int bit = !(v&1);
  return po[bit] == 0?po[bit^1]:po[bit];
}

int ans=-1,ansl,ansr;

void setAns(int v1,int l,int r){
  // cout<<"SETANS:"<<v1<<" l:"<<l<<" r:"<<r<<endl;
  if(l > r){
    swap(l,r);
  }
  if(v1 < ans)return;
  if(v1 > ans){
    ans = v1;
    ansl = l;
    ansr = r;
    return ;
  }
  if(r < ansr){
    ansl = l;
    ansr = r;
    return ;
  }
  if(r > ansr){
    return ;
  }
  if(l > ansl){
    ansl = l;
    return ;
  }
}

int main(){
  usefile();
  scanf("%d",&n);
  rep(i,0,n){
    scanf("%d",a+i);
  }
  rep(i,0,n){
    p[i+1]=p[i]^a[i];
  }
  rep(i,0,n+1){
    build(i);
  }
  // for(auto item:pv2idx){
  //   cout<<"--------"<<item.first<<endl;
  //   for(auto z:item.second){
  //     cout<<z<<"\t"<<endl;
  //   }
  //   cout<<endl;
  // }
  rep(i,0,n+1){
    int ret = query(i);
    int reti = lower_bound(pv2idx[ret].begin(),pv2idx[ret].end(),i)-pv2idx[ret].begin();
    // cout<<"find:"<<i<<"["<<p[i]<<"]:"<<ret<<"("<<pv2idx[ret][reti]<<")"<<endl;
    if(ret == p[i]){
      if(i > 0){
        setAns(ret^p[i],i-1,i);
      }
    }else if(reti > 0){
      setAns(ret^p[i],i,pv2idx[ret][reti-1]);
    }else{
      setAns(ret^p[i],i,pv2idx[ret][reti]);
    }
  }
  printf("%d %d %d\n",ans,ansl+1,ansr);
  return 0;
}
