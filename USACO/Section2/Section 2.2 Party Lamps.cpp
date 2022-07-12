/*
ID: 10157591
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream inc("lamps.in");
ofstream outc("lamps.out");
int n;
int may[][10]={
	{1,63},
	{4,0,21,27,42},
	{7,0,14,21,36,42,49,63},
	{8,0,14,21,27,36,42,49,63},
	{8,0,14,21,27,36,42,49,63}};
int kai[10]={0},guan[10]={0};
int light[10];
void output(int num)
{
	int i;
	for(i=0;i<n;i++)
	{
		int j=i%6;
		if(num&(1<<(5-j)))outc<<1;
		else outc<<0;
	}
	outc<<endl;
}
void f(int c)
{
	int j,k;
	bool youshuchu=false;
	for(k=1;k<=may[c][0];k++)
	{
		bool ok=true;
		for(j=0;j<6;j++)
		{
			if(light[j]!=-1)
			{
				if((light[j]<<(5-j))^(may[c][k]&(1<<(5-j))))
				{
					ok=false;
					break;
				}
			}
		}
		if(ok)
		{
			youshuchu=true;
			output(may[c][k]);
		}
	}
	if(!youshuchu)
	{
		outc<<"IMPOSSIBLE"<<endl;
	}
}
int main()
{
	int c;
	inc>>n>>c;
	int i;
	while(inc>>i)
	{
		if(i==-1)
			break;
		kai[(i-1)%6]=1;
	}
	while(inc>>i)
	{
		if(i==-1)
			break;
		guan[(i-1)%6]=1;
	}
	for(i=0;i<6;i++)
	{
		if(kai[i] || guan[i])
		{
			if(kai[i] && guan[i])
			{
				cout<<"IMPOSSIBLE"<<endl;
				return 0;
			}
			light[i]=kai[i];
		}
		else light[i]=-1;
	}
	if(c<3)
		f(c);
	else if(c%2)
		f(3);
	else
		f(4);
    return 0;
}


