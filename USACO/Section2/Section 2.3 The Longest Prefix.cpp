/*
ID: 10157591
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
char ys[210][20];
char mb[200010];
int lenmb=0;
bool ans[200010]={0};
int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b); 
}
int main()
{
    ifstream inc("prefix.in");
    ofstream outc("prefix.out");
	int jg=0;
	int n=0;
	while(inc>>ys[n])
	{
		if(ys[n][0]!='.')
			n++;
		else 
			break;
	}
	int i;
	qsort(ys,n,sizeof(char)*20,cmp);
	char eachline[100];
	while(inc>>eachline)
	{
		int leneach=strlen(eachline),i;
		for(i=0;i<=leneach;i++)
		{
			mb[lenmb+i]=eachline[i];
		}
		lenmb=lenmb+leneach;
	}
	ans[0]=true;
	for(i=0;i<lenmb;i++)
	{
		if(!ans[i])continue;
		int l=0;
		char comp[20];
		while(l<n)
		{
			int lenl=strlen(ys[l]);
			memcpy(comp,mb+i,lenl);
			comp[lenl]='\0';
			int compres=strcmp(ys[l],comp);
			if(compres==0)
			{
				ans[i+lenl]=true;
				jg=jg>(i+lenl)?jg:(i+lenl);
			}
			else if(compres>0)
				break;
			l++;
		}
	}
	outc<<jg<<endl;
    return 0;
}


