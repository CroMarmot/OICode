/*
ID: 10157591
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("fact4.in");
ofstream outc("fact4.out");
int num[4500];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
		num[i]=i;
}
int getfive(int n)
{
	int i;
	int times=0;
	for(i=1;i<=n;i++)
		while(!(num[i]%5))
		{
			num[i]/=5;
			times++;
		}
	return times;
}
int result(int n)
{
	int i;
	int res=1;
	for(i=1;i<=n;i++)
		res=(res*(num[i]%10))%10;
	return res;
}
void moveouttwo(int m,int n)
{
	int times=m;
	int i;
	for(i=1;i<=n;i++)
		while(times!=0 && (!(num[i]%2)))
		{
			num[i]/=2;
			times--;
		}
}
int main()
{
	int n;
	inc>>n;
	init(n);
	moveouttwo(getfive(n),n);
	outc<<result(n)<<endl;
    return 0;
}

