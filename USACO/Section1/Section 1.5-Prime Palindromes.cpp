/*
ID: 10157591
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream inc("pprime.in");
ofstream outc("pprime.out");

long long shi[]= {1,10,100,1000,10000,100000,1000000,10000000,100000000};
long long a,b;

bool ok(long long num)
{
    if(num>=a && num<=b)return true;
    return false;
}

bool zs(long long num)
{
	int i=2,halfnum=sqrt(num);
	for(;i<=halfnum;i++)
	{
		if(!(num%i))return false;
	}
	return true;
}

void f(int n,long long num,int len)
{
    if(n==0)
    {
        if(ok(num))
            if(zs(num))
                outc<<num<<endl;
    }
    else if(n==1)
    {
        int j;
        for(j=0; j<=9; j++)
        {
            long long testnum=num+(num/shi[len/2])*shi[len/2]*9+j*shi[len/2];
            if(ok(testnum))
                if(zs(testnum))
                    outc<<testnum<<endl;
        }
    }
    else
    {
        int j;
        for(j=0; j<=9; j++)
        {
            f(n-2,num+(num/shi[len/2])*shi[len/2]*99+j*11*shi[len/2],len+2);
        }
    }
}

int main()
{
    inc>>a>>b;
    long long i,j;
    int k;
    for(k=1; k<9; k++)f(k,0,0);
    return 0;
}

