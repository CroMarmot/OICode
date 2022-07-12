/*
ID: 10157591
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#define syear 1900
using namespace std;
int md[13]= {0,3,0,3,2,3,2,3,3,2,3,2,3};
int ans[7]= {0};
int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin>>n;
    int i,j;
    int we=6;
    for(i=0; i<n; i++)
    {
        if((syear+i)%100==0)
        {
            if((syear+i)%400==0)
            {
                md[2]=1;
            }
            else
            {
                md[2]=0;
            }
        }
        else
        {
            if((syear+i)%4==0)
            {
                md[2]=1;
            }
            else
            {
                md[2]=0;
            }
        }

        for(j=1; j<=12; j++)
        {
            ans[we]++;
            we=(we+md[j])%7;
        }
    }
    fout<<ans[6];
    for(j=0; j<6; j++)
    {
        fout<<" "<<ans[j];
    }
    fout<<endl;
    return 0;
}
