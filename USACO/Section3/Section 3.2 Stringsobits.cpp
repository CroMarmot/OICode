/*
ID: 10157591
PROG: kimbits 
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("kimbits.in");
ofstream outc("kimbits.out");
long long fangfa[40][40]={0};// i j 表示 i 个1 的 j 位个数
long long fafa[40][40]={0};// i j 表示 <=i 个1 的 j 位个数
void init(int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		fangfa[0][i]=1;
		fangfa[i][i]=1;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			fangfa[i][j]=fangfa[i][j-1]+fangfa[i-1][j-1];
			//outc<<i<<","<<j<<":"<<fangfa[i][j]<<endl;
		}
	for(j=0;j<=n;j++)
	{
		fafa[0][j]=fangfa[0][j];
		for(i=1;i<=j;i++)
			fafa[i][j]+=fangfa[i][j]+fafa[i-1][j];
		for(i=j+1;i<=n;i++)
			fafa[i][j]=fafa[i-1][j];
	}
	return ;
}
int main()
{
	int n,l;
	long long k;
	inc>>n>>l>>k;
	init(n);
	int i,j;
	if(k==1)
	{
		for(i=0;i<n;i++)
			outc<<0;
		outc<<endl;
		return 0;
	}
	int res[40]={0};
	while(k!=0)
	{
		//outc<<"K:"<<k<<endl;
		for(i=0;i<=n;i++)
			if(k<=fafa[l][i])
			{
				res[n-i]=1;
				if(i>0)
					k-=fafa[l][i-1];
				else
					k=0;
				l--;
				break;
			}
	}
	for(i=0;i<n;i++)
	{
		outc<<res[i];
	}
	outc<<endl;
    return 0;
}


