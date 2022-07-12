/*
ID: 10157591
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int lu[200][200];
int is[60],fis[200];//ying she ** fan ying she
void init()
{
	int i;
	for(i=0;i<26;i++)
	{
		is[i]='a'+i;
		fis['a'+i]=i;
	}
	for(i=26;i<52;i++)
	{
		is[i]='A'-26+i;
		fis['A'-26+i]=i;
	}
	return ;
}
int main()
{
    ifstream inc("comehome.in");
    ofstream outc("comehome.out");
	memset(lu,-1,sizeof(lu));
	init();
	int n,ii;
	inc>>n;
	char a,b;
	int l;
	for(ii=0;ii<n;ii++)
	{
		inc>>a>>b>>l;
		if(lu[fis[a]][fis[b]]==-1 || lu[fis[a]][fis[b]]>l)
		{
			lu[fis[a]][fis[b]]=l;
			lu[fis[b]][fis[a]]=l;
		}
	}
	int k,i,j;
	for(i=0;i<52;i++)
		lu[i][i]=0;
	for(k=0;k<52;k++)
	{
		for(i=0;i<52;i++)
		{
			for(j=0;j<52;j++)
			{
				if(lu[i][k]!=-1 && lu[j][k]!=-1)
				{
					if(lu[i][j]==-1 || lu[i][j]>lu[i][k]+lu[j][k])
					{
						lu[i][j]=lu[i][k]+lu[j][k];
						lu[j][i]=lu[i][j];
					}
				}
			}
		}
	}
	int zuiduan=-1,bh;
	for(i=26;i<51;i++)
	{
		if(lu[i][51]!=-1)
		{
			if(zuiduan==-1 || lu[i][51]<zuiduan)
			{
				zuiduan=lu[i][51];
				bh=i;
			}
		}
	}
	outc<<char(is[bh])<<" "<<zuiduan<<endl;
    return 0;
}


