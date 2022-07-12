/*
ID: 10157591
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
struct sq
{
    int Width;
    int Height;
};
sq s[4];
int outp[400];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int ansnum;
int minsize=-1;
int maxab(int num1,int num2)
{
    return num1>num2?num1:num2;
}
int maxx(int num1,int num2,int num3,int num4)
{
    int ans;
    ans=maxab(num1,num2);
    ans=maxab(ans,num3);
    ans=maxab(ans,num4);
    return ans;
}
void add_w(int kk,int cc)
{
    if(kk*cc>minsize)return;
    if(kk>cc)
    {
        int temp=kk;
        kk=cc;
        cc=temp;
    }
    if(kk*cc==minsize)
    {
        outp[ansnum]=kk;
        ansnum++;
    }
    else
    {
        outp[0]=kk;
        ansnum=1;
        minsize=kk*cc;
    }
}
void cacu(int w1,int h1,int w2,int h2,int w3,int h3,int w4,int h4)
{
    int kuan,chang;
    //1
    kuan=maxx(w1,w2,0,0)+w3+w4;
    chang=maxx(h1+h2,h3,h4,0);
    if(minsize==-1)
    {
        minsize=kuan*chang+1;
        add_w(kuan,chang);
    }
    else
    {
        add_w(kuan,chang);
    }
    //2
    kuan=w1+w2+w3+w4;
    chang=maxx(h1,h2,h3,h4);
    add_w(kuan,chang);
    //3
    kuan=maxx(w1+w2+w3,w4,0,0);
    chang=maxx(h1,h2,h3,0)+h4;
    add_w(kuan,chang);
    //4
    kuan=maxx(maxx(w1,w2,0,0)+w3,w4,0,0);
    chang=maxx(h1+h2,h3,0,0)+h4;
    add_w(kuan,chang);
    //5
    kuan=maxx(w1,w2,0,0)+maxx(w3,w4,0,0);
    chang=maxx(h1+h2,h3+h4,0,0);
    add_w(kuan,chang);
    //6
    if(w2<=w1 && h3>=h1)
    {
        kuan=maxx(w1+w3,w2+w4,0,0);
        chang=maxx(h1+h2,h3+h4,0,0);
        add_w(kuan,chang);
    }
}
int main()
{
    ifstream inc("packrec.in");
    ofstream outc("packrec.out");
    int i;
    for(i=0; i<4; i++)
    {
        inc>>s[i].Width>>s[i].Height;
    }
    int a[4];
    for(a[0]=0; a[0]<4; a[0]++)
    {
        for(a[1]=0; a[1]<4; a[1]++)
        {
            if(a[1]==a[0])continue;
            for(a[2]=0; a[2]<4; a[2]++)
            {
                if(a[2]==a[0] || a[2]==a[1])continue;
                a[3]=6-a[0]-a[1]-a[2];
                int j;
                for(j=0; j<16; j++) //取值方案
                {
                    int wid[4],hei[4];
                    int q,w;
                    for(w=0; w<4; w++)
                    {
                        q=(1<<w)&j;//位运算获取方案
                        if(q!=0)//取旋转
                        {
                            wid[w]=s[a[w]].Height;
                            hei[w]=s[a[w]].Width;
                        }
                        else//取本身
                        {
                            wid[w]=s[a[w]].Width;
                            hei[w]=s[a[w]].Height;
                        }
                    }
                    cacu(wid[0],hei[0],wid[1],hei[1],wid[2],hei[2],wid[3],hei[3]);
                }
            }
        }
    }
    qsort(outp,ansnum,sizeof(outp[0]),cmp);
    outc<<minsize<<endl;
    for(i=0; i<ansnum; i++)
    {
        if(i==0 || outp[i-1]!=outp[i])
            outc<<outp[i]<<" "<<minsize/outp[i]<<endl;
    }
    return 0;
}
