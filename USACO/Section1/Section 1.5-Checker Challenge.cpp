/*
ID: 10157591
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("checker.in");
ofstream outc("checker.out");

int lie[13]={0},zx[25]={0},fx[25]={0};//行 列 正斜 反斜
int n;
int acount=0;
int nowans[13]={0};
void printans()
{
	int i;
	if(acount<3)
	{
		outc<<nowans[0];
		for(i=1;i<n;i++)
		{
			outc<<" "<<nowans[i];
		}
		outc<<endl;
	}
	acount++;
}
void f(int i)
{
	if(i==n)
	{
		printans();
		return;
	}
	int j;
	for(j=0;j<n;j++)
	{
		if((!lie[j]) && (!zx[i+j]) && (!fx[j-i+n-1]))
		{
			lie[j]=1;
			zx[i+j]=1;
			fx[j-i+n-1]=1;
			nowans[i]=j+1;
			f(i+1);
			lie[j]=0;
			zx[i+j]=0;
			fx[j-i+n-1]=0;
		}
	}
}
int main()
{
	inc>>n;
	f(0);
	outc<<acount<<endl;
    return 0;
}




