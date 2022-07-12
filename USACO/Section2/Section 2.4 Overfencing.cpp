/*
ID: 10157591
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream inc("maze1.in");
ofstream outc("maze1.out");
int derx[]={0,1,0,-1},dery[]={-1,0,1,0};
int er[]={1,2,4,8};
int n,m;
int mg[110][50]={0};
int value[110][50]={0};
void get1(int i)
{
	char s1[100];
	inc.getline(s1,2*n+2);
	//cout<<s1<<" "<<i<<endl;
	int lens=strlen(s1);
	int j;
	for(j=0;j<=2*n;j+=2)
	{
		if(s1[j]=='|')
		{
			mg[i][j/2]+=2;
			mg[i][j/2+1]+=8;
		}
	}
}
void get2(int i)
{
	char s2[100];
	inc.getline(s2,2*n+2);
	//cout<<s2<<" "<<i<<endl;
	int lens=strlen(s2);
	int j;
	for(j=1;j<=2*n;j+=2)
	{
		if(s2[j]=='-')
		{
			mg[i][j/2+1]+=4;
			mg[i+1][j/2+1]+=1;
		}
	}
}
int main()
{
	inc>>n>>m;
	char guolv[10];
	inc.getline(guolv,10);
	get2(0);
	int i;
	for(i=1;i<=m;i++)
	{
		get1(i);
		get2(i);
	}
    int st=0,rear=0,dl[5000];
	for(i=1;i<=n;i++)
	{
		if(!(mg[1][i]&1))
			dl[rear++]=i;
		if(!(mg[m][i]&4))
			dl[rear++]=(m-1)*n+i;
	}
	for(i=1;i<=m;i++)
	{
		if(!(mg[i][1]&8))
			dl[rear++]=(i-1)*n+1;
		if(!(mg[i][n]&2))
			dl[rear++]=i*n;
	}
	int j;
	/*
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			outc<<mg[i][j]<<" ";
		}
		outc<<endl;
	}
	*/
	for(i=0;i<rear;i++)
	{
		value[(dl[i]-1)/n+1][(dl[i]-1)%n+1]=1;
	}
	while(st<rear)
	{
		int stx=(dl[st]-1)%n+1,sty=(dl[st]-1)/n+1;
		//cout<<sty<<" "<<stx<<endl;
		int j;
		for(j=0;j<4;j++)
		{
			if(!(mg[sty][stx]&er[j]))
			{
				int nextx=stx+derx[j],nexty=sty+dery[j];
				if(nextx>0 && nexty>0 && nexty<=m && nextx<=n && 
						(!value[nexty][nextx]))
				{
					value[nexty][nextx]=value[sty][stx]+1;
					dl[rear++]=(nexty-1)*n+nextx;
				}
			}
		}
		st++;
	}
	/*
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			outc<<value[i][j]<<" ";
		}
		outc<<endl;
	}
	*/
	outc<<value[(dl[st-1]-1)/n+1][(dl[st-1]-1)%n+1]<<endl;
	return 0;
}


