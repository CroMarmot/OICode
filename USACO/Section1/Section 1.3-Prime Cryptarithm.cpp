/*
ID: 10157591
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
bool num[10];
int main()
{
    ifstream inc("crypt1.in");
    ofstream outc("crypt1.out");
    int n,i,u;
    for(i=0; i<10; i++)num[i]=false;
    inc>>n;
    for(i=0; i<n; i++)
    {
        inc>>u;
        num[u]=true;
    }
    int a1,a2,a3,a;
    int b1,b2,b;
    int ans=0;
    for(a1=1; a1<10; a1++)
        for(a2=1; a2<10; a2++)
            for(a3=1; a3<10; a3++)
                if(num[a1]==true && num[a2]==true && num[a3]==true)
                {
                    a=a1*100+a2*10+a3;
                    for(b1=1; b1<10; b1++)
                        for(b2=1; b2<10; b2++)
                        {
                            if(num[b1]==true && num[b2]==true)
                            {
                                b=b1*10+b2;
                                int chk1,chk2,chk3;
                                chk1=a*b1;
                                chk2=a*b2;
                                chk3=a*b;
                                if(chk1>100 && chk1 <1000 && chk2>100 && chk2 <1000 && chk3>1000 && chk3 <10000 )
                                {
                                    int n1,n2,n3,n4;
                                    n1=chk1/100;
                                    n2=(chk1-100*n1)/10;
                                    n3=chk1%10;
                                    if(num[n1]!=true || num[n2]!=true || num[n3]!=true)continue;
                                    n1=chk2/100;
                                    n2=(chk2-100*n1)/10;
                                    n3=chk2%10;
                                    if(num[n1]!=true || num[n2]!=true || num[n3]!=true)continue;
                                    n1=chk3/1000;
                                    n2=(chk3-1000*n1)/100;
                                    n3=(chk3-1000*n1-100*n2)/10;
                                    n4=chk3%10;
                                    if(num[n1]!=true || num[n2]!=true || num[n3]!=true || num[n4]!=true)continue;
                                    //outc<<a<<" "<<b<<" "<<chk1<<" "<<chk2<<" "<<chk3<<endl;
                                    ans++;
                                }
                            }
                        }
                }
    outc<<ans<<endl;
    return 0;
}
