/*
ID: 10157591
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream inc("palsquare.in");
    ofstream outc("palsquare.out");
    int num[20];
    int n;
    inc>>n;
    long i;
    for(i=1; i<=300; i++)
    {
        int B;
        B=i*i;
        //转换
        int w=0;
        while(B!=0)
        {
            num[w++]=B%n;
            B/=n;
        }//while(B!=0)
        int j;
        bool ok=true;
        for(j=0; j<w/2; j++)
        {
            if(num[j]!=num[w-j-1])
            {
                ok=false;
                break;
            }//if
        }//for(j=0;j<w/2;j++)
        if(ok==true)
        {
            B=i;
            int wc;
            wc=0;
            while(B!=0)
            {
                num[wc++]=B%n;
                B/=n;
            }//while(B!=0)
            while(wc-->0)
            {
                if(num[wc]>9)outc<<char('A'+(num[wc]-10));
                else outc<<num[wc];
            }
            outc<<" ";

            B=i*i;
            wc=0;
            while(B!=0)
            {
                num[wc++]=B%n;
                B/=n;
            }//while(B!=0)
            while(wc-->0)
            {
                if(num[wc]>9)outc<<char('A'+(num[wc]-10));
                else outc<<num[wc];
            }
            outc<<endl;
        }//if
    }
    return 0;
}
