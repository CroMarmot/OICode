/*
ID: 10157591
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int er[]={1,2,4,8,16};
int deri[]={0,-1,0,1},derj[]={-1,0,1,0};
int cb[60][60][4]={0};//0无墙 1有墙
int cbsize[60][60]={0};//0初始 !0计算过 房间大小
int cbn[60][60]={0};//0初始 !0计算过 房间编号
int maxnew=0,data[3]={0};//最大的新房间 其数据
int maxx(int num1,int num2)
{
	return num1>num2?num1:num2;
}
void renew(int newsize,int i,int j,int k)
{
	if(maxnew<newsize)
	{
		maxnew=newsize;
		data[0]=i+1;//与题设不同
		data[1]=j+1;//与题设不同
		data[2]=k==1?'N':'E';
	}
}
int main()
{
    ifstream inc("castle.in");
    ofstream outc("castle.out");
	int m,n,i,j;
	inc>>m>>n;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			int k;
			int num;
			inc>>num;
			for(k=0;k<4;k++)
			{
				if(er[k]&num)cb[i][j][k]=1;
			}
		}
	int housenum=0,maxhouse=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(!cbsize[i][j])//未计算过
			{
				housenum++;//房间个数
				int acount=0;
				int st=0,rear=1;
				int dl[2510]={0};

				dl[0]=i*64+j;
				cbsize[i][j]=-1;
				acount=1;
				while(st<rear)
				{
					int nowi=dl[st]/64,nowj=dl[st]%64;
					int k;
					for(k=0;k<4;k++)
						if(!cb[nowi][nowj][k])
						{
							int newi=nowi+deri[k],newj=nowj+derj[k];
							if(!cbsize[newi][newj])
							{
								cbsize[newi][newj]=-1;
								acount++;
								dl[rear]=newi*64+newj;
								rear++;
							}
						}
					st++;
				}
				int k;
				for(k=0;k<rear;k++)
				{
					cbsize[dl[k]/64][dl[k]%64]=acount;
					cbn[dl[k]/64][dl[k]%64]=housenum;
				}
				maxhouse=maxx(maxhouse,acount);
			}
		}
	for(j=0;j<m;j++)
		for(i=n-1;i>=0;i--)
		{
			if(i!=0)
			{
				if(cb[i][j][1])//有墙
				{
					if(cbn[i+deri[1]][j+derj[1]]!=cbn[i][j])//非同一房间
						renew(cbsize[i][j]+cbsize[i+deri[1]][j+derj[1]],i,j,1);
				}
			}
			if(j<m-1)
			{
				if(cb[i][j][2])//有墙
				{
					if(cbn[i+deri[2]][j+derj[2]]!=cbn[i][j])//非同一房间
						renew(cbsize[i][j]+cbsize[i+deri[2]][j+derj[2]],i,j,2);
				}
			}
		}
	outc<<housenum<<endl;
	outc<<maxhouse<<endl;
	outc<<maxnew<<endl;
	outc<<data[0]<<" "<<data[1]<<" "<<char(data[2])<<endl;
	return 0;
}


