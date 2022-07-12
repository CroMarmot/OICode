/*
ID: 10157591
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int k[10],a[10];
char ans[40],anslen=-1;
void DFS(int deep)
{
    if(deep==9)
    {
        if((a[0]+a[1]+a[3]              +k[0])%4!=0)return;
        if((a[0]+a[1]+a[2]+a[4]     +k[1])%4!=0)return;
        if((a[1]+a[2]+a[5]              +k[2])%4!=0)return;
        if((a[0]+a[3]+a[4]+a[6]         +k[3])%4!=0)return;
        if((a[0]+a[2]+a[4]+a[6]+a[8]    +k[4])%4!=0)return;
        if((a[2]+a[4]+a[5]+a[8]             +k[5])%4!=0)return;
        if((a[3]+a[6]+a[7]                  +k[6])%4!=0)return;
        if((a[4]+a[6]+a[7]+a[8]         +k[7])%4!=0)return;
        if((a[5]+a[7]+a[8]              +k[8])%4!=0)return;

        int count=0,j;
        char thisres[40];
        for(j=0; j<9; j++)
        {
            int R=a[j];
            while(R-- >0)
            {
                thisres[count]=j+1+'0';
                count++;
            }
        }
        if(anslen==-1 || count<anslen)
        {
            int t;
            for(t=0; t<count; t++)
            {
                ans[t]=thisres[t];
            }
            anslen=count;
        }
        else if(count==anslen)
        {
            int t;
            for(t=0; t<count; t++)
            {
                if(ans[t]>thisres[t])
                {
                    for(; t<count; t++)
                        ans[t]=thisres[t];
                }
                else if(ans[t]<thisres[t])break;
            }
        }
        return ;
    }
    int j;
    for(j=0; j<4; j++)
    {
        a[deep]=j;
        DFS(deep+1);
    }
}
int main()
{
    ifstream inc("clocks.in");
    ofstream outc("clocks.out");
    int i;
    for(i=0; i<9; i++)
    {
        inc>>k[i];
        k[i]=(k[i]/3)%4;
    }
    DFS(0);
    outc<<ans[0];
    for(i=1; i<anslen; i++)
    {
        outc<<" "<<ans[i];
    }
    outc<<endl;
    return 0;
}
