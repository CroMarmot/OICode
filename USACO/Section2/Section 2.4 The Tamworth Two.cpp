/*
ID: 10157591
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("ttwo.in");
ofstream outc("ttwo.out");
int derx[]={0,1,0,-1},dery[]={-1,0,1,0};
struct	thing
{
	int x,y;
	int fx;
};
thing man,cow;
int stone[20][20]={0};
int n=10;
bool cang(int x,int y,int fx)
{
	int newx=x+derx[fx],newy=y+dery[fx];
	if(newx<1)return false;
	if(newy<1)return false;
	if(newx>n)return false;
	if(newy>n)return false;
	if(stone[newy][newx])return false;
	return true;
}
void movcf()
{
	if(cang(man.x,man.y,man.fx))
	{
		man.x=man.x+derx[man.fx];
		man.y=man.y+dery[man.fx];
	}
	else
		man.fx=(man.fx+1)%4;
	if(cang(cow.x,cow.y,cow.fx))
	{
		cow.x=cow.x+derx[cow.fx];
		cow.y=cow.y+dery[cow.fx];
	}
	else
		cow.fx=(cow.fx+1)%4;
	return ;
}
void init()
{
	char got[20];
	int i,j;
	for(i=1;i<=n;i++)
	{
		inc>>got;
		for(j=1;j<=n;j++)
		{
			char nowp=got[j-1];
			if(nowp=='*')
				stone[i][j]=1;
			else if(nowp=='F')
			{
				man.x=j;
				man.y=i;
			}
			else if(nowp=='C')
			{
				cow.x=j;
				cow.y=i;
			}
		}
	}
	man.fx=0;
	cow.fx=0;
}
int main()
{
	init();
	int ti;
	for(ti=0;ti<=64000;ti++)
	{
		if(man.x==cow.x && man.y==cow.y)
		{
			outc<<ti<<endl;
			return 0;
		}
		movcf();
		int i,j;
		/*for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==man.y && j==man.x)
					outc<<"F";
				else if(i==cow.y && j==cow.x)
					outc<<"C";
				else
					outc<<stone[i][j];
				
			}
			outc<<endl;
		}
		outc<<endl;*/
	}
	outc<<0<<endl;
    return 0;
}
