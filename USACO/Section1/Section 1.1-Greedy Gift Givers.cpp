/*
ID: 10157591
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char pn[20][20];
int pi[20]= {0};
int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    fin >> n;
    int i;
    for(i=0; i<n; i++)
        fin>>pn[i];
    for(i=0; i<n; i++)
    {
        char pe[20];
        fin>>pe;

        int j;
        for(j=0; j<n; j++)if(strcmp(pe,pn[j])==0)break;
        int sr,sc;
        fin>>sr>>sc;
        //pi[j]+=sr;
        int k;
        for(k=0; k<sc; k++)
        {
            char pg[20];
            fin>>pg;
            int w;
            for(w=0; w<n; w++)if(strcmp(pg,pn[w])==0)break;
            pi[w]+=sr/sc;
            pi[j]-=sr/sc;
        }
    }
    for(i=0; i<n; i++)
        fout<<pn[i]<<" "<<pi[i]<<endl;
    //fout <<endl;
    return 0;
}
