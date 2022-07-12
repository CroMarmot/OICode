/*
ID: 10157591
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
struct p
{
    char c;//color
    int num;
};
char l[800];
p po[800];
int ge=0;//part num

int maxx(int num1,int num2)
{
    return num1>num2?num1:num2;
}
int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    //Input
    fin>>n;
    fin>>l;
    int i;
    for(i=0; i<n; i++)
    {
        l[i+n]=l[i];
    }
    l[i+n]='\0';
    //Ñ¹Ëõ
    for(i=0; i<2*n; i++)
    {
        if(i>0 && l[i]==l[i-1])//same as before
        {
            po[ge-1].num++;//add num
        }
        else
        {
            po[ge].c=l[i];//add color
            po[ge].num++;//add num
            ge++;//num adding
        }
    }
    //Í¬»¯°×É«
    if(po[0].c=='w')po[0].c=po[1].c;
    if(po[ge-1].c=='w')po[ge-1].c=po[ge-2].c;
    for(i=0+1; i<ge-1; i++)
    {
        if(po[i].c=='w')
        {
            if(po[i-1].c==po[i+1].c)po[i].c=po[i-1].c;
        }
    }
    //Ñ¹Ëõ
    int gg=0;
    for(i=0; i<ge; i++)
    {
        if(i>0 && po[i].c==po[i-1].c)//same as before
        {
            po[gg-1].num+=po[i].num;//add num
        }
        else
        {
            po[gg].c=po[i].c;//rewrite color
            po[gg].num=po[i].num;//rewrite num
            gg++;//num adding
        }
    }
    int ans=0;
    for(i=0; i<ge; i++)
    {
        char stcolor,count=0;
        int j=i;
        if(po[i].c=='w')
        {
            j++;
            count+=po[i].num;
        }
        stcolor=po[j].c;
        count+=po[j].num;
        j++;
        while(j<ge && po[j].c!=stcolor)
        {
            count+=po[j].num;
            j++;
        }
        ans=maxx(ans,count);
    }
    if(ans>n)fout<<n<<endl;//too less color
    else fout<<ans<<endl;
    return 0;
}
