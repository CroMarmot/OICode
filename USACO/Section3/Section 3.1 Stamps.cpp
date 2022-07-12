/*
ID: 10157591
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("stamps.in");
ofstream outc("stamps.out");
int minn(int num1,int num2)
{
	return num1<num2?num1:num2;
}
int n,k;
int stamps[100];
int can[2000000]={0};
int main()
{
	inc>>k>>n;
	int i;
	for(i=0;i<n;i++)
	{
		inc>>stamps[i];
		can[stamps[i]]=1;
	}
	i=1;
	while(can[i]>0)
	{
		if(can[i]==k)
		{
			i++;
			continue;
		}
		int j;
		for(j=0;j<n;j++)
		{
			if(can[i+stamps[j]]==0)
				can[i+stamps[j]]=can[i]+1;
			else
				can[i+stamps[j]]=minn(can[i+stamps[j]],can[i]+1);
		}
		i++;
	}
	outc<<i-1<<endl;
    return 0;
}


