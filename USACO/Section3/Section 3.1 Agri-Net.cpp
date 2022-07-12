/*
ID: 10157591
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
ifstream inc("agrinet.in");
ofstream outc("agrinet.out");
int fa[110];
struct lu
{
	int x,y;
	int lenth;
}way[10010];
int cmp(const void *a,int const void *b)
{
	return ((lu*)a)->lenth-((lu*)b)->lenth;
}
int main()
{
	int n,i,j;
	cin>>n;
	memset(fa,-1,sizeof(fa));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			cin>>way[i*100+j].lenth;
			way[i*100+j].y=i;
			way[i*100+j].x=j;
		}
	qsort(way,n,sizeof(way[0]),cmp);
	int acount=0;

    return 0;
}
