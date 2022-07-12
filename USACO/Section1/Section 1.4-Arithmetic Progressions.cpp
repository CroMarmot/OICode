/*
ID: 10157591
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int h[125010]= {0};
int main()
{
    ifstream inc("ariprog.in");
    ofstream outc("ariprog.out");
    long n,m,i,j;
    inc>>n>>m;
    for(i=0; i<=m; i++)
        for(j=i; j<=m; j++)
        {
            h[i*i+j*j]=1;
        }
    long maxnum=m*m*2/(n-1);
    long b;
    bool have=false;
    for(b=1; b<=maxnum; b++)
    {
        int a;
        int maxa=2*m*m-(n-1)*b;
        for(a=0; a<=maxa; a++)
        {
            bool ok=true;
            int testnum,maxtest=a+(n-1)*b;
            for(testnum=a; testnum<=maxtest; testnum+=b)
            {
                if(h[testnum]!=1)
                {
                    ok=false;
                    break;
                }
            }
            if(ok==true)
            {
                outc<<a<<" "<<b<<endl;
                have=true;
            }
        }
    }
    if(have==false)outc<<"NONE"<<endl;
    return 0;
}
