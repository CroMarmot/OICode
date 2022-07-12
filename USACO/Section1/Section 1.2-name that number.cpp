/*
ID: 10157591
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
char jian[10][3]= {{},{},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
using namespace std;

int main()
{
    ifstream indata("dict.txt");
    ifstream inc("namenum.in");
    ofstream outc("namenum.out");
    char n[20];
    inc>>n;
    int wei=strlen(n);
    char data[20];
    int output=false;
    while(indata>>data)
    {
        if(strlen(data)!=wei)continue;
        int i,ok=true;
        for(i=0; i<wei; i++)
        {
            bool right=false;
            int j;
            for(j=0; j<3; j++)
            {
                if(data[i]==jian[n[i]-'0'][j])
                {
                    right=true;
                    break;
                }
            }
            if(right==false)
            {
                ok=false;
                break;
            }
        }
        if(ok==true)
        {
            output=true;
            outc<<data<<endl;
        }
    }
    if(output==false)outc<<"NONE"<<endl;
    return 0;
}
