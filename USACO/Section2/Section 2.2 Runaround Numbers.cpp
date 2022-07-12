/*
ID: 10157591
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

ifstream inc("runround.in");
ofstream outc("runround.out");
int num[20]={0};
int now[20]={0};
int ys[20]={0};
int len,lenn;
bool morebig()
{
	if(len>lenn)return true;
	int i;
	for(i=len-1;i>=0;i--)
	{
		if(now[i]>ys[i])return true;
		if(now[i]<ys[i])return false;
	}
	return false;
}
bool tj()
{
	if(!morebig())return false;
	int i=len-1;
	int ti=0;
	int marked[20]={0};
	while(ti<len)
	{
		i=(i+9*len-now[i])%len;
		if(marked[i])return false;
		marked[i]=1;
		ti++;
	}
	return true;
}
bool f(int i)
{
	int j;
	if(i==-1)
	{
		if(tj())
		{
			for(i=len-1;i>=0;i--)
			{
				outc<<now[i];
			}
			outc<<endl;
			return true;
		}
		else return false;
	}
	for(j=1;j<10;j++)
	{
		if(!num[j])
		{
			now[i]=j;
			num[j]=1;
			if(f(i-1))return true;
			num[j]=0;
		}
	}
	return false;
}
int main()
{
	long long n;
	int i;
	inc>>n;
	for(i=0;i<10;i++)
	{
		if(n==0)break;
		ys[i]=n%10;
		n=n/10;
	}
	len=i;
	lenn=i;
	for(;len<10;len++)
	{
		if(f(len-1))return 0;
	}
    return 0;
}


