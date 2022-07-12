/*
ID: 10157591
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include<stdio.h>
using namespace std;
struct Word
{
    char zf;
    int orig;
};
Word zh[20010];
int maxx(int num1,int num2)
{
    return num1>num2?num1:num2;
}
int main()
{
    FILE *fp;//定义一个文件指针
    fp=freopen("calfflac.in","r",stdin);
    int maxlen=0;
    //ifstream inc("calfflac.in");
    ofstream outc("calfflac.out");
    char data[20010];
    char hang[20010];
    int i=0,j=0,len;
    while(i<20010 && scanf("%c",&data[i])!=0)
    {
        i++;
    }
    len=strlen(data);
    for(i=0; i<len; i++)
    {
        if(data[i]>='a' && data[i]<='z')
        {
            zh[j].zf=data[i]-'a'+'A';
            zh[j].orig=i;
            j++;
        }
        else if(data[i]>='A' && data[i]<='Z')
        {
            zh[j].zf=data[i];
            zh[j].orig=i;
            j++;
        }
    }
    int anslen=0;
    int zlen=j;
    int le,ri;
    for(i=0; i<zlen; i++)
    {
        int maxj;
        maxj=maxx(i,zlen-i-1);
        for(j=0; j<=maxj; j++)
        {
            if(zh[i-j].zf==zh[i+j].zf)
            {
                if(maxlen<zh[i+j].orig-zh[i-j].orig+1)
                {
                    maxlen=zh[i+j].orig-zh[i-j].orig+1;
                    le=zh[i-j].orig;
                    ri=zh[i+j].orig;
                    anslen=maxx(anslen,2*j+1);
                }
            }
            else
            {
                break;
            }
        }
        maxj=maxx(i,zlen-i-2);
        for(j=0; j<=maxj; j++)
        {
            if(zh[i-j].zf==zh[i+j+1].zf)
            {
                if(maxlen<zh[i+j+1].orig-zh[i-j].orig+1)
                {
                    maxlen=zh[i+j+1].orig-zh[i-j].orig+1;
                    le=zh[i-j].orig;
                    ri=zh[i+j+1].orig;
                    anslen=maxx(anslen,2*(j+1));
                }
            }
            else
            {
                break;
            }
        }
    }
    outc<<anslen<<endl;
    for(i=le; i<=ri; i++)
        outc<<data[i];
    outc<<endl;
    return 0;
}
