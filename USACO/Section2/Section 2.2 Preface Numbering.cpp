/*
ID: 10157591
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int ans[4000]={0};
int shi[]={1,10,100,1000,10000};
char word[]={'I','V','X','L','C','D','M'};
int f(int i,int num)
{
	if(num%5==4)
	{
		ans[i*2]++;
		ans[(num+1)/5+i*2]++;
	}
	else
	{
		ans[i*2]+=num%5;
		if(num>4)ans[num/5+i*2]++;
	}
}
int main()
{
    ifstream inc("preface.in");
    ofstream outc("preface.out");
	int n,i;
	inc>>n;
	while(n>0)
	{
		for(i=0;i<4;i++)
			f(i,(n/shi[i])%10);
		n--;
	}
	for(i=0;i<7;i++)
		if(ans[i])
			outc<<word[i]<<" "<<ans[i]<<endl;
    return 0;
}

