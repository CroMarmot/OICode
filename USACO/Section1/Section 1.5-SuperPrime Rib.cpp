/*
ID: 10157591
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
long long zhishu[100];
int zsnum[10]={0};
int numcount=0;
bool zs(long long num)
{
	int i,seminum=int(sqrt(num));
	for(i=2;i<=seminum;i++)
	{
		if(!(num%i))return false;
	}
	return true;
}
void outprime(int size)
{
	if(size==1)
	{
		zsnum[size]=0;
		zhishu[0]=2;
		zhishu[1]=3;
		zhishu[2]=5;
		zhishu[3]=7;
		numcount+=4;
		zsnum[size+1]=4;
	}
	else
	{
		int st=zsnum[size];
		int i;
		int wy=0;//Î»ÒÆ
		for(i=zsnum[size-1];i<st;i++)
		{
			int j;
			for(j=1;j<10;j++)
			{
				if(j==1 || j==3 || j==7 || j==9)
				{
					if(zs(zhishu[i]*10+j))
					{
						numcount++;
						zhishu[st+wy]=zhishu[i]*10+j;
						wy++;
					}
				}
			}
		}
		zsnum[size+1]=wy+zsnum[size];
	}
}
int main() 
{
    ifstream inc("sprime.in");
    ofstream outc("sprime.out");
	int n,i;
	inc>>n;
	for(i=1;i<=n;i++)
	{
		outprime(i);
	}
	for(i=zsnum[n];i<zsnum[n+1];i++)
	{
		outc<<zhishu[i]<<endl;
	}
	return 0;
}

