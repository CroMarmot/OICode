/*
ID: 10157591
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream inc("inflate.in");
ofstream outc("inflate.out");
int ti[10010],v[10010];
int value[10010];
int maxx(int num1,int num2)
{
	return num1>num2?num1:num2;
}
int main()
{
	int T,n,i,j;
	inc>>T>>n;
	memset(value,-1,sizeof(value));
	value[0]=0;
	for(i=0;i<n;i++)
		inc>>v[i]>>ti[i];
	for(i=0;i<n;i++)
		for(j=ti[i];j<=T;j++)
		{
			if(j-ti[i]>=0 && value[j-ti[i]]!=-1)
			{
				value[j]=maxx(value[j],value[j-ti[i]]+v[i]);
			}
		}
	int maxnum=0;
	for(i=0;i<=T;i++)
		maxnum=maxx(maxnum,value[i]);
	outc<<maxnum<<endl;
	return 0;
}


