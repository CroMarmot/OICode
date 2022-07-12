/*
ID: 10157591
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

char tran_y[20][20];
char tran_m[20][20];
int main()
{
    ifstream inc("transform.in");
    ofstream outc("transform.out");
    int n;
    inc>>n;
    int i,j;
    for(i=0; i<n; i++)inc>>tran_y[i];
    for(i=0; i<n; i++)inc>>tran_m[i];
    bool brek;
    //1
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[j][n-i-1])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<1<<endl;
        return 0;
    }
    //2
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[n-i-1][n-j-1])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<2<<endl;
        return 0;
    }
    //3
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[n-j-1][i])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<3<<endl;
        return 0;
    }
    //4
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[i][n-j-1])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<4<<endl;
        return 0;
    }
    //5
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[n-j-1][n-i-1])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<5<<endl;
        return 0;
    }
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[n-i-1][j])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<5<<endl;
        return 0;
    }
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[j][i])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<5<<endl;
        return 0;
    }
    //6
    brek=false;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(tran_y[i][j]!=tran_m[i][j])
            {
                brek=true;
                break;
            }//if
        }//for j
        if(brek==true)break;
    }//for i
    if(brek==false)
    {
        outc<<6<<endl;
        return 0;
    }
    //7
    outc<<7<<endl;
    return 0;
}
