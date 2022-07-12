/*
ID: 10157591
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
long peo[1000010]= {0}; //人数
long minn(long num1,long num2)
{
    return num1>num2?num2:num1;
}
long maxx(long num1,long num2)
{
    return num1>num2?num1:num2;
}
int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin>>n;
    int i;
    long fs,le;
    fs=1000010;
    le=0;
    long s,e;
    for(i=0; i<n; i++)
    {
        fin>>s>>e;
        fs=minn(fs,s);
        le=maxx(le,e);
        int j;
        for(j=s; j<e; j++)
        {
            peo[j]=1;
        }
    }
    int ans1=0,ans2=0;
    int nownum=0,nowstyle=0;
    for(i=fs; i<le; i++)
    {
        if(peo[i]==0)
        {
            if(nowstyle==0)
            {
                nownum++;
                ans2=maxx(nownum,ans2);
            }
            else if(nowstyle==1)
            {
                nowstyle=0;
                nownum=1;
                ans2=maxx(nownum,ans2);
            }
        }
        else
        {
            if(nowstyle==1)
            {
                nownum++;
                ans1=maxx(nownum,ans1);
            }
            else if(nowstyle==0)
            {
                nowstyle=1;
                nownum=1;
                ans1=maxx(nownum,ans1);
            }
        }
    }
    fout<<ans1<<" "<<ans2<<endl;
    return 0;
}
