/*
ID: 10157591
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int num[1010];
int geshu[4]={0};
int dernum[4][4]={0};//dernum[i][j] i中j的个数
int ans=0;
void add_ans(int i,int j)
{
		ans+=dernum[j][i];
		dernum[i][j]-=dernum[j][i];
		dernum[j][i]=0;
}
void R_do(int i,int j)
{
	if(dernum[i][j]>dernum[j][i])add_ans(i,j);
	else add_ans(j,i);
}
int main()
{
    ifstream inc("sort3.in");
    ofstream outc("sort3.out");
	int n;
	int i,j;
	inc>>n;
	for(i=0;i<n;i++)
	{
		inc>>num[i];
		geshu[num[i]]++;
	}
	//应该结束的位置
	geshu[2]+=geshu[1];
	geshu[3]+=geshu[2];
	//dernum[i][j] i中j的个数
	i=0;
	for(j=1;j<=3;j++)
	{
		for(;i<geshu[j];i++)
		{
			dernum[j][num[i]]++;
		}
	}
	R_do(1,2);
	R_do(2,3);
	R_do(3,1);
	ans+=2*(dernum[1][2]+dernum[2][1]);
	outc<<ans<<endl;
	return 0;
}
