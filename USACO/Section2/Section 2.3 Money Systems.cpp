/*
ID: 10157591
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const long long size1 = 30;
const long long size2 = 10010;

long long ans[size1][size2];
long long useable[size1];
long long f(int i,int left)
{
	if(ans[i][left]!=-1)return ans[i][left];
	if(left<useable[i])return ans[i][left]=f(i-1,left);
	int j,maxj=left/useable[i];
	ans[i][left]=0;
	for(j=0;j<=maxj;j++)
		ans[i][left]+=f(i-1,left-j*useable[i]);
	return ans[i][left];
}
int main()
{
    ifstream inc("money.in");
    ofstream outc("money.out");
	int v,n,i;
	inc>>v>>n;
	for(i=0;i<v;i++)
		inc>>useable[i];
	memset(ans,-1,sizeof(ans));
	for(i=0;i<=n;i++)
	{
		if(i%useable[0])
			ans[0][i]=0;
		else
			ans[0][i]=1;
	}
	outc<<f(v-1,n)<<endl;
    return 0;
}


