/*
ID: 10157591
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ifstream inc("cowtour.in");
ofstream outc("cowtour.out");
struct point
{
	double x;
	double y;
}p[160];
int map[160][160];
int jh[160]={0};
double dis[160][160];
double maxdis[160]={0};
double mudis[160];
int mcg=1;//the number of the farm
int shi[10]={1,10,100,1000,10000,100000};
double pdis(int i,int j)
{
	return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}
void bcj(int i,int n)//bing cha ji
{
	jh[i]=mcg;
	int j;
	for(j=0;j<n;j++)
	{
		if(map[i][j])//link?
		{
			if(jh[j]==0)//haven't mark
				bcj(j,n);
		}
	}
	return ;
}
double maxx(double num1,double num2)
{
	return num1>num2?num1:num2;
}
void init(int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dis[i][j]=-1;
	//get zuo biao
	for(i=0;i<n;i++)
	{
		inc>>p[i].x>>p[i].y;
		dis[i][i]=0;
	}
	//get lian jie	
	for(i=0;i<n;i++)
	{
		char zt[160];
		inc>>zt;
		for(j=0;j<n;j++)
		{
			map[i][j]=zt[j]-'0';
			if(map[i][j]==1)
			{
				dis[i][j]=pdis(i,j);
				dis[j][i]=dis[i][j];
			}
		}
	}
	//fen lei
	for(i=0;i<n;i++)
	{
		if(jh[i]==0)
		{
			bcj(i,n);
			mcg++;
		}
	}
}
int main()
{
	int n,i,j;
	inc>>n;
	init(n);
	int w,k;
	for(w=1;w<mcg;w++)
	{
		for(k=0;k<n;k++)
			if(jh[k]==w)
				for(i=0;i<n;i++)
					if(jh[i]==w)
						for(j=0;j<n;j++)
							if(jh[j]==w)
								if(dis[i][k]>=0 && dis[j][k]>=0)
									if(dis[i][j]<0 || dis[i][j]>dis[i][k]+dis[j][k])
										dis[i][j]=dis[i][k]+dis[j][k];
		for(i=0;i<n;i++)
		{
			if(jh[i]==w)
				for(j=0;j<n;j++)
					if(jh[j]==w)
						maxdis[i]=maxx(maxdis[i],dis[i][j]);
			if(mudis[w]<maxdis[i])
				mudis[w]=maxdis[i];
		}
	}
	double mindis=-1;
	for(w=1;w<mcg;w++)
	{
		for(i=0;i<n;i++)
			if(jh[i]==w)
				for(j=0;j<n;j++)
					if(jh[j]>w)
					{
						double newlen=pdis(i,j)+maxdis[i]+maxdis[j];
						if(newlen<mudis[jh[i]])newlen=mudis[jh[i]];
						if(newlen<mudis[jh[j]])newlen=mudis[jh[j]];
						if(mindis==-1 || newlen<mindis)
							mindis=newlen;
					}
	}
	int anszheng=int(mindis);
	int ansxiao=int((mindis-double(anszheng))*10000000);
	if(ansxiao%10>4)
		ansxiao+=10;
	ansxiao/=10;
	outc<<anszheng<<".";
	for(i=5;i>=0;i--)
	outc<<(ansxiao/shi[i])%10;
	outc<<endl;
    return 0;
}


