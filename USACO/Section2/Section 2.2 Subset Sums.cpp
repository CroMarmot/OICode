/*
ID: 10157591
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int sigma[40]={0};
int ans[40][400];
void init()
{
	int i;
	for(i=1;i<40;i++)
	{
		sigma[i]=sigma[i-1]+i;
	}
}
int f(int i,int sum)
{
	if(ans[i][sum]!=-1)
		return ans[i][sum];
	if(sum<1 || sigma[i]-sum<0)return 0;
	return ans[i][sum]=f(i-1,sum)+f(i-1,sum-i);
}
int main()
{
    ifstream inc("subset.in");
    ofstream outc("subset.out");
	int n;
	inc>>n;
	if((((n+1)*n)/2)%2)
	{
		outc<<0<<endl;
		return 0;
	}
	init();
	memset(ans,-1,sizeof(ans));
	ans[1][1]=1;
	outc<<f(n,((n+1)*n)/4)<<endl;
    return 0;
}


