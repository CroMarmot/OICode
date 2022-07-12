/*
ID: 10157591
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int bs[110][110]={0};
int by[110][110]={0};
bool sg[110][110]={0};
int main()
{
    ifstream inc("concom.in");
    ofstream outc("concom.out");
	int n,i,j;
	inc>>n;
	int a,b,c;
	for(i=1;i<=n;i++)
	{
		inc>>a>>b>>c;
		by[a][b]=c;
		bs[a][b]=c;
	}
	bool newnum=true;
	while(newnum)
	{
		newnum=false;
		for(i=1;i<=100;i++)
		{
			for(j=1;j<=100;j++)
			{
				if(!sg[i][j] && bs[i][j]>50)
				{
					newnum=true;
					sg[i][j]=true;
					int k;
					for(k=1;k<=100;k++)
						bs[i][k]+=by[j][k];
				}
			}
		}
	}
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=100;j++)
		{
			if(i!=j && sg[i][j])
				outc<<i<<" "<<j<<endl;
		}
	}
    return 0;
}
