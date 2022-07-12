/*
ID: 10157591
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
struct cow
{
    long v;
    long long num;
};
cow nainiu[5010];
int cmp(const void *a,const void *b)
{
    return (((cow*)a)->v)-(((cow*)b)->v);
}
int main()
{
    ifstream inc("milk.in");
    ofstream outc("milk.out");
    long long v_all,ans=0;
    long n,i;
    inc>>v_all>>n;
    for(i=0; i<n; i++)
    {
        inc>>nainiu[i].v>>nainiu[i].num;
    }
    qsort(nainiu,n,sizeof(cow),cmp);
    for(i=0; i<n; i++)
    {
        if(v_all==0)break;
        if(v_all>nainiu[i].num)
        {
            v_all-=nainiu[i].num;
            ans+=nainiu[i].v*nainiu[i].num;
        }
        else
        {
            ans+=nainiu[i].v*v_all;
            v_all=0;
        }
    }
    outc<<ans<<endl;
    return 0;
}
