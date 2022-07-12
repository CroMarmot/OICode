/*
ID: 10157591
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int v,n;
int choose[1010]={0};
int cow[30];
int food[1010][30];
bool ok()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		int nowf=0;
		for(j=0;j<n;j++)
		{
			if(choose[j])nowf+=food[j][i];
		}
		if(nowf<cow[i])return false;
	}
	return true;
}
bool f(int st,int size)
{
	if(size==0)
	{
		if(ok())return true;
		else return false;
	}
	int i;
	for(i=st;i<=n-size;i++)
	{
		choose[i]=1;
		if(f(i+1,size-1))return true;
		choose[i]=0;
	}
	return false;
}
int main()
{
    ifstream inc("holstein.in");
    ofstream outc("holstein.out");
	int i,j;
	inc>>v;
	for(i=0;i<v;i++)
		inc>>cow[i];
	inc>>n;
	for(i=0;i<n;i++)
		for(j=0;j<v;j++)
			inc>>food[i][j];
	i=1;
	while(i<=n && !f(0,i))i++;
	outc<<i;
	for(i=0;i<n;i++)if(choose[i])outc<<" "<<i+1;
	outc<<endl;
	return 0;
}


