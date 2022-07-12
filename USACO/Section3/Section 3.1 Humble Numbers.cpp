/*
ID: 10157591
PROG: humble 
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("humble.in");
ofstream outc("humble.out");
long long cs[100010]={0};//丑数
long long zs[110];//质数
long long zsc[110]={0};//将乘的那个数的编号
int main()
{
	int k,n,i,j=0;
	inc>>k>>n;
	for(i=0;i<k;i++)
		inc>>zs[i];
	cs[0]=1;//假装1是丑数
	while(j<n)
	{
		//outc<<"----------------------------"<<"j:"<<j<<"-----------------------------"<<endl;
		//outc<<"cs["<<j<<"]:"<<cs[j]<<endl;
		long long nmin = 2*zs[0] * cs[zsc[0]], ni;
		//outc<<"start nmin:"<<nmin<<endl;
		int w;
		for( w=0 ; w<k ; w++)
		{
			long long newcs=zs[w] * cs[zsc[w]];
			//outc<<w<<","<<newcs;
			if(newcs==cs[j])
			{
				zsc[w]++;
				newcs=zs[w] * cs[zsc[w]];
			}
			if( newcs > cs[j])
			{
				if( newcs < nmin)
				{
					nmin=newcs;
					ni=w;
					//outc<<"*";
				}
			}
			//outc<<endl;
		}
		//outc<<"end nmin:"<<nmin<<endl;
		cs[j+1]=nmin;
		zsc[ni]++;
		j++;
	}
	//for(i=0;i<=n;i++)
	outc<<cs[n]<<endl;
    return 0;
}


