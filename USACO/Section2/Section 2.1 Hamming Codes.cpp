/*
ID: 10157591
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int num[70];
int b,d;
bool ok(int testnum,int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		int k,acount=0;
		for(k=0;k<b;k++)
		{
			if((testnum &(1<<k))^(num[j] & (1<<k)))acount++;
		}
		if(acount<d)return false;
	}
	return true;
}
int main()
{
    ifstream inc("hamming.in");
    ofstream outc("hamming.out");
	int n,i;
	inc>>n>>b>>d;
	num[0]=0;
	int rear=1;
	while(rear<n)
	{
		int j=num[rear-1]+1;
		while(!ok(j,rear))j++;
		num[rear++]=j;
	}
	for(i=0;i<n;i++)
	{
		if(i%10==0)outc<<num[i];
		else if(i%10==9)outc<<" "<<num[i]<<endl;
		else outc<<" "<<num[i];
	}
	if(n%10!=0)outc<<endl;
	return 0;
}


