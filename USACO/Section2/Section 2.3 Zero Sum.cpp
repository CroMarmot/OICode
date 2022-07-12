/*
ID: 10157591
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("zerosum.in");
ofstream outc("zerosum.out");
int n;
int cho[10];
bool check()
{
	int nowans=0,nowf=1,nownum=1;
	int i;
	for(i=1;i<n;i++)
	{
		if(cho[i]==0)
			nownum=nownum*10+(i+1);
		else if(cho[i]==1)
		{
			if(nowf==1)
			{
				nowans+=nownum;
				nownum=i+1;
			}
			else if(nowf==2)
			{
				nowans-=nownum;
				nowf=1;
				nownum=i+1;
			}
		}
		else if(cho[i]=2)
		{
			if(nowf==1)
			{
				nowans+=nownum;
				nowf=2;
				nownum=i+1;
			}
			else if(nowf==2)
			{
				nowans-=nownum;
				nownum=i+1;
			}
		}
	}
	if(nowf==1)
	{
		nowans+=nownum;
		nownum=i+1;
	}
	else if(nowf==2)
	{
		nowans-=nownum;
		nownum=i+1;
	}
	if(nowans==0)
		return true;
	else
		return false;
}
void shuchu()
{
	int i;
	for(i=1;i<n;i++)
	{
		outc<<i;
		switch(cho[i])
		{
			case 0:
				outc<<" ";
				break;
			case 1:
				outc<<"+";
				break;
			case 2:
				outc<<"-";
				break;
		}
	}
	outc<<n<<endl;
}
void f(int num)
{
	if(num==n)
	{
		if(check())
			shuchu();
		return ;
	}
	int i;
	for(i=0;i<3;i++)
	{
		cho[num]=i;
		f(num+1);
	}

}
int main()
{
	inc>>n;
	f(1);
	return 0;
}


