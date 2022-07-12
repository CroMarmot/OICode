/*
ID: 10157591
PROG: contact 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
ifstream inc("contact.in");
ofstream outc("contact.out");
int san[]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147};
struct ge
{
	int yuan;
	int value;
}Rcount[600010];
int cmp(void const *a,void const *b)
{
	if(((ge *)b)->value==((ge *)a)->value)
		return ((ge *)a)->yuan-((ge *)b)->yuan;
	else
		return ((ge *)b)->value-((ge *)a)->value;
}
void init()
{
	int i;
	for(i=0;i<600010;i++)
	{
		Rcount[i].yuan=i;
		Rcount[i].value=0;
	}
}
void fcout(int num)
{
	int outshu[20],lenos=0;
	int i=num;
	while(i!=0)
	{
		outshu[lenos++]=i%3-1;
		i/=3;
	}
	for(i=lenos-1;i>=0;i--)
	{
		outc<<outshu[i];
	}
}
int main()
{
	init();
	int low,high,n;
	inc>>low>>high>>n;
	char a[200010],b[100];
	a[0]='\0';
	while(inc>>b)
	{
		strcat(a,b);
	}
	int lenstr=strlen(a);
	high=high>lenstr?lenstr:high;
	int chang;
	int i;
	for(i=0;i<lenstr;i++)
	{
		a[i]=a[i]+1;
	}
	for(chang=low;chang<=high;chang++)
	{
		int nownum=0;
		for(i=chang;i>0;i--)
			nownum=nownum*3+(a[lenstr-i]-'0');
		//get nownum;
		Rcount[nownum].value++;
		for(i=lenstr-chang-1;i>=0;i--)
		{
			nownum=nownum/3+san[chang-1]*(a[i]-'0');
			Rcount[nownum].value++;
		}
	}
	qsort(Rcount,600010,sizeof(Rcount[0]),cmp);
	int k=1,nowge=Rcount[0].value;
	int fullsix=0;
	outc<<nowge<<endl;
	fcout(Rcount[0].yuan);
	for(i=1;i<600010;i++)
		if(nowge==Rcount[i].value)
		{
			if(fullsix==6)
			{
				outc<<endl;
				fullsix=1;
				fcout(Rcount[i].yuan);
			
			}
			else
			{
				outc<<" ";
				fcout(Rcount[i].yuan);//shu
				fullsix++;
			}
		}
		else
		{
			if(k==n ||Rcount[i].value==0)
			{
				outc<<endl;
				return 0;
			}
			nowge=Rcount[i].value;
			outc<<endl<<nowge<<endl;//endl chuli
			fcout(Rcount[i].yuan);
			k++;
			fullsix=1;
		}
	outc<<endl;
    return 0;
}


