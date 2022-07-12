/*
ID: 10157591
PROG: numtri
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream inc("numtri.in");
ofstream outc("numtri.out");
int ans[1010]= {0};
int outnum=0;
int maxx(int num1,int num2)
{
    return num1>num2?num1:num2;
}
int main()
{
    int i,j,n;
    inc>>n;
    for(i=0; i<n; i++)
    {
        for(j=i; j>0; j--)
        {
            ans[j]=maxx(ans[j],ans[j-1]);
        }
        for(j=0; j<=i; j++)
        {
            int addnum;
            inc>>addnum;
            ans[j]+=addnum;
        }
    }
    for(i=0; i<n; i++)
    {
        outnum=maxx(outnum,ans[i]);
    }
    outc<<outnum<<endl;
    return 0;
}
