/*
ID: 10157591
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int ans[210][110][2];
int f(int num,int hei,int st)
{
	if(ans[num][hei][st]!=-1)return ans[num][hei][st];
	if(hei==1)
	{
		if(num==1)
			return ans[num][hei][st]=1;
		else
			return ans[num][hei][st]=0;
	}
	if(num==1)
	{
		if(st==0)
			return ans[num][hei][st]=1;
		else if(st==1)
			return ans[num][hei][st]=0;
	}
	if(st==0)
	{
		int i,sum=0;
		for(i=1;i<num-1;i++)
			sum+=(f(i,hei-1,0)*f(num-i-1,hei-1,0))%9901;
		return ans[num][hei][st]=sum%9901;
	}
	else if(st==1)
	{
		int i,sum1=0,sum2=0;
		for(i=1;i<num-1;i++)
			sum1+=(f(i,hei-1,1)*f(num-i-1,hei-1,0))%9901;
		for(i=1;i<num-1;i++)
			sum2+=(f(i,hei-1,1)*f(num-i-1,hei-1,1))%9901;
		return ans[num][hei][st]=(2*sum1-sum2)%9901;
	}
}
int main()
{
    ifstream inc("nocows.in");
    ofstream outc("nocows.out");
	memset(ans,-1,sizeof(ans));
	int k,n;
	inc>>n>>k;
	outc<<f(n,k,1)<<endl;
    return 0;
}


