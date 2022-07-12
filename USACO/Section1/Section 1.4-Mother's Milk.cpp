/*
ID: 10157591
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream inc("milk3.in");
    ofstream outc("milk3.out");
    int a,b,c;
    inc>>a>>b>>c;
    if(a>=c && b<c)
    {
        int outp=c-b;
        outc<<outp;
        for(outp++; outp<=c; outp++)if(c-(c%b)==outp || outp==c)outc<<" "<<outp;
        outc<<endl;
    }
    else if(b>=c && a<c)
    {
        int outp=0;
        outc<<outp;
        for(outp++; outp<=c; outp++)if(outp%a==0 || (c-outp)%a==0)outc<<" "<<outp;
        outc<<endl;
    }
    else if(a>=c  && b>=c)
    {
        int outp=0;
        outc<<outp;
        for(outp++; outp<=c; outp++)if(outp==c)outc<<" "<<outp;
        outc<<endl;
    }
    else
    {
        int can[30][30][30]= {0};
        can[0][0][c]=1;
        int st=0,rear=1;
        int WFS[8010];
        WFS[0]=c;
        while(st<rear)
        {
            int nowa,nowb,nowc;
            nowa=WFS[st]/21/21;
            nowb=(WFS[st]/21)%21;
            nowc=WFS[st]%21;
            //cout<<st<<" "<<nowa<<" "<<nowb<<" "<<nowc<<endl;
            int newa,newb,newc;
            //a->b
            if(nowa+nowb>b)//a有剩余
            {
                newa=nowa+nowb-b;
                newb=b;
                newc=nowc;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            else
            {
                newa=0;
                newb=nowa+nowb;
                newc=nowc;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            //b->a
            if(nowa+nowb>a)//b有剩余
            {
                newa=a;
                newb=nowa+nowb-a;
                newc=nowc;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            else
            {
                newa=nowa+nowb;
                newb=0;
                newc=nowc;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            //b->c
            if(nowb+nowc>c)//b有剩余
            {
                newa=nowa;
                newb=nowb+nowc-c;
                newc=c;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            else
            {
                newa=nowa;
                newb=0;
                newc=nowc+nowb;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            //c->b
            if(nowb+nowc>b)//c有剩余
            {
                newa=nowa;
                newb=b;
                newc=nowb+nowc-b;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            else
            {
                newa=nowa;
                newb=nowb+nowc;
                newc=0;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            //c->a
            if(nowa+nowc>a)//c有剩余
            {
                newa=a;
                newb=nowb;
                newc=nowa+nowc-a;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            else
            {
                newa=nowa+nowc;
                newb=nowb;
                newc=0;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            //a->c
            if(nowa+nowc>c)//a有剩余
            {
                newa=nowa+nowc-c;
                newb=nowb;
                newc=c;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            else
            {
                newa=0;
                newb=nowb;
                newc=nowa+nowc;
                if(can[newa][newb][newc]==0)
                {
                    can[newa][newb][newc]=1;
                    WFS[rear]=newa*21*21+newb*21+newc;
                    rear++;
                }
            }
            st++;
            cout<<"**";
        }
        int outp=c-b;
        outc<<outp;
        for(outp++; outp<=c; outp++)if(can[0][c-outp][outp]==1)outc<<" "<<outp;
        outc<<endl;
    }
    return 0;
}
