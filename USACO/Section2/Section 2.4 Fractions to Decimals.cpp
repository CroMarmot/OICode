/*
ID: 10157591
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
long long fm=0,fz=0;
long long shang[1000010];
bool fenzi[100010]={0};
bool fzweizhi[100010];
long long num=0;//len_xiaoshu
int gotlen(int shu)
{
	if(shu==0)return 1;
	int acount=0;
	while(shu>0)
	{
		acount++;
		shu/=10;
	}
	return acount;
}
int main()
{
    ifstream inc("fracdec.in");
    ofstream outc("fracdec.out");
	int i,j;
	inc>>fz>>fm;
	int zsbf=int(fz/fm);
	fz%=fm;
	while(fz!=0)
	{
		fenzi[fz]=true;//now fz
		fzweizhi[fz]=num;//the location of fz
		shang[num++]=(fz*10)/fm;//qiu shang
		fz=(fz*10)%fm;//the next fz
		if(fenzi[fz])//have calc
			break;
	}
	long long xhw=fzweizhi[fz];//the location that xunhuan
	outc<<zsbf<<".";
	long long lenz=gotlen(zsbf);//got the lenth of zhezs
	if(num==0)
	{
		outc<<0<<endl;
	}
	else if(fz==0)//wuxunhuan
	{
		for(i=0;i<num;i++)
			outc<<shang[i];
		outc<<endl;
	}
	else
	{
		for(i=0;i<xhw;i++)
			outc<<shang[j];
		outc<<"(";
		for(i=xhw;i<num;i++)
		{
			if((i+2+lenz)%76==0)outc<<endl;
			outc<<shang[i];
		}
		if((num+2+lenz)%76==0)outc<<endl;
		outc<<")"<<endl;
	}
    return 0;
}


