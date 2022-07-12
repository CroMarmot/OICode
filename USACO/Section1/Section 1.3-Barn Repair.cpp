/*
ID: 10157591
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int np[210]= {0};
int interval[210]= {0};
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
    ifstream inc("barn1.in");
    ofstream outc("barn1.out");
    int m,s,c;
    inc>>m>>s>>c;
    int i;
    for(i=0; i<c; i++)
    {
        int cst;
        inc>>cst;
        np[cst]=1;
    }
    i=1;
    while(np[i]!=1)i++;
    while(np[s]!=1)s--;
    int ans=s-i+1;
    for(; i<=s; i++)
    {
        if(np[i]==0)
        {
            interval[np[0]]++;
        }
        else if(interval[np[0]]!=0)
        {
            np[0]++;
        }
    }
    qsort(interval ,np[0],sizeof (interval[0]),cmp);
    for(i=0; i<m-1; i++)
    {
        ans-=interval[i];
    }
    outc<<ans<<endl;
    return 0;
}
