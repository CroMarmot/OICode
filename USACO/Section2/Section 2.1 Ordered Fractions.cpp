/*
ID: 10157591
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
struct num
{
	int a,b;
};
num res[25600];
int cmp(const void *num1,const void *num2)
{
	int a1,b1,a2,b2;
	a1=((num*)num1)->a;
	b1=((num*)num1)->b;
	a2=((num*)num2)->a;
	b2=((num*)num2)->b;
	return a1*b2-a2*b1;
}
bool gcd(int num1,int num2)
{
	if(num1==1 || num2==1)return true;
	if(num1%num2==0 || num2%num1==0)return false;
	return gcd(num1%num2,num2%num1);
}
int main()
{
    ifstream inc("frac1.in");
    ofstream outc("frac1.out");
	int n,i,j;
	inc>>n;
	int acount=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(gcd(i,j))
			{
				res[acount].b=i;
				res[acount].a=j;
				acount++;
			}
		}
	}
	qsort(res,acount,sizeof(res[0]),cmp);
	outc<<"0/1"<<endl;
	for(i=0;i<acount;i++)
	{
		outc<<res[i].a<<"/"<<res[i].b<<endl;
	}
	return 0;
}
