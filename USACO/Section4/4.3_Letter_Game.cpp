/*
ID: 10157591
PROG: lgame
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

string filename = "lgame";

void usefile(){
  freopen((filename+".in").c_str(),"r",stdin);
  freopen((filename+".out").c_str(),"w",stdout);
}

int scor[]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};

char d[40010][10];
int s[40010]={0};
int len[40010]={0};
int n;
char query[10];



bool analy(int i,int * quercnt){
  int j;
  int charcnt[30];
  memset(charcnt,0,30*sizeof(int));
  len[i]=strlen(d[i]);
  s[i] = 0;
  for(j=0;j<len[i];j++){
    int tmp = d[i][j]-'a';
    s[i]+=scor[tmp];
    charcnt[tmp]++;
    if(charcnt[tmp] > quercnt[tmp]){
      return false;
    }
  }
  return true;
}
int maxv = 0;
vector< vector<int> > ans;
void makeans(int i0,int i1,int cost){
  if(cost < maxv)
    return ;
  if(cost > maxv){
    maxv = cost;
    ans.clear();
  }
  vector<int> tmp ;
  if(i1 < 0)
    tmp.push_back(i0);
  else if(i0 < i1){
    tmp.push_back(i0);
    tmp.push_back(i1);
  }else if(i1 < i0){
    tmp.push_back(i1);
    tmp.push_back(i0);
  }
  ans.push_back(tmp);
}
void tryi2(int index,int fai,string str){
  int j;
  for(j=0;j<len[index];j++){
    bool findv= false;
    for(int i=0;i<str.length();i++){
      if(str[i] == d[index][j]){
        str.erase(i,1);
        findv = true;
        break;
      }
    }
    if(!findv)
      return ;
  }
  if(fai == -1)
    makeans(index,-1,s[index]);
  else
    makeans(fai,index,s[fai]+s[index]);
}

void tryi(int index){
  string str= query;
  int j;
  for(j=0;j<len[index];j++){
    for(int i=0;i<str.length();i++){
      if(str[i] == d[index][j]){
        str.erase(i,1);
        break;
      }
    }
  }
  makeans(index,-1,s[index]);
  if(str.length()>=3){
    for(j=index+1 ; j<n ;j++){
      if(len[j] <= str.length() ){
        tryi2(j,index,str);
      }
    }
  }
}

int main(){
  usefile();
  cin>>query;
  int charcnt[30];
  memset(charcnt,0,30*sizeof(int));
  int i;
  for(i=0;i<strlen(query);i++)
    charcnt[query[i]-'a']++;

  ifstream dict("lgame.dict");
  n=0;
  while(dict >> d[n]){
    if(d[n][0] == '.')
      break;
    if(analy(n,charcnt))
      n++;
  }

  for(i=0;i<n;i++)
    tryi(i);

  cout<<maxv<<endl;
  for(i=0;i<ans.size();i++){
    if(ans[i].size() == 1)
      cout<<d[ans[i][0]]<<endl;
    else
      cout<<d[ans[i][0]]<<" "<<d[ans[i][1]]<<endl;
  }
  return 0;
}
