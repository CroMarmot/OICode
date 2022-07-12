/*
ID: 10157591
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char a[10], b[10];
    fin >> a >> b;
    int fa=1,fb=1;
    int i;
    for(i=0; i<strlen(a); i++)
        fa=(fa*(a[i]-'A'+1))%47;
    for(i=0; i<strlen(b); i++)
        fb=(fb*(b[i]-'A'+1))%47;
    if(fa==fb)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
