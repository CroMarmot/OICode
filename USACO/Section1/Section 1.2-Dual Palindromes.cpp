/*
ID: 10157591
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
bool is_pali(long numb,int jz)
{
    int num[20];
    int B;
    B=numb;
    //转换
    int w=0;//记录长度
    while(B!=0)
    {
        num[w++]=B%jz;
        B/=jz;
    }//while(B!=0)
    //检测回文
    int j;
    for(j=0; j<w/2; j++)
    {
        if(num[j]!=num[w-j-1])
        {
            return false;
        }//if
    }//for(j=0;j<w/2;j++)
    return true;
}
int main()
{
    ifstream inc("dualpal.in");
    ofstream outc("dualpal.out");
    int n;
    long s;
    inc>>n>>s;
    long i=s,count=0,jz;
    for(i++; n>0 && count<2; i++,count=0) //i-当前所测试的数 count-满足进制个数
    {
        for(jz=2; jz<=10; jz++) //枚举每一种进制
        {
            if(is_pali(i,jz)==true)//jz进制下是回文
            {
                count++;
                if(count>1)
                {
                    n--;
                    outc<<i<<endl;
                    break;
                }//if
            }//if 是回文
        }//for jz
    }
    return 0;
}
