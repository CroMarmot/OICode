/*
ID: 10157591
PROG: rect1 
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("rect1.in");
ofstream outc("rect1.out");
int n;
struct cfx
{
	int lx,ly,rx,ry,color;
};
cfx fk[1010];
int colorcount[2510]={0};
void f(int l_x,int l_y,int r_x,int r_y,int f_color,int k)
{
	while ( k<n && ( 
				r_x<=fk[k].lx ||
				l_x>=fk[k].rx ||
				r_y<=fk[k].ly ||
				l_y>=fk[k].ry 
				))
		k++;
	if (k==n)
	{
		colorcount[f_color]+=(r_y-l_y)*(r_x-l_x); 
		return ;
	}
	if(l_x<=fk[k].lx)
	{
		f(l_x,		l_y,		fk[k].lx,	r_y,		f_color,k+1);
		l_x=fk[k].lx;
	}
	if(r_x>=fk[k].rx)
	{
		f(fk[k].rx,	l_y,		r_x,		r_y,		f_color,k+1);
		r_x=fk[k].rx;
	}
	if(l_y<=fk[k].ly)
	{
		f(l_x,		l_y,		r_x,		fk[k].ly,	f_color,k+1);
		l_y=fk[k].ly;
	}
	if(r_y>=fk[k].ry)
	{
		f(l_x,		fk[k].ry,	r_x,		r_y,		f_color,k+1);
		r_y=fk[k].ry;
	}
	return ;
}
int main()
{
	int a,b,i;
	inc>>a>>b>>n;
	for(i=0;i<n;i++)
	{
		inc>>fk[i].lx>>fk[i].ly>>fk[i].rx>>fk[i].ry>>fk[i].color;
	}
	for(i=n-1;i>=0;i--)
		f(fk[i].lx,fk[i].ly,fk[i].rx,fk[i].ry,fk[i].color,i+1);
	int color1=a*b;
	for(i=2;i<2501;i++)
		color1-=colorcount[i];
	outc<<"1 "<<color1<<endl;
	for(i=2;i<2501;i++)
		if(colorcount[i])
			outc<<i<<" "<<colorcount[i]<<endl;
    return 0;
}


