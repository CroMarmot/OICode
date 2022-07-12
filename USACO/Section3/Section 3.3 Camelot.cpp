/*
ID: 10157591
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
ifstream inc("camelot.in");
ofstream outc("camelot.out");
int R,C;
int step[40][40] = {0}; // king
int knightstep[40][40] = {0}; //for calc knight
int cntpage[40][40] = {0}; // for res
int bringking[40][40] = {0};
int minder[40][40] = {0};
int wsearch[4000] = {0};

void king(int r,int c){
  int derx[] = {-1,-1,-1,0,0,0,1,1,1};
  int dery[] = {-1,0,1,-1,0,1,-1,0,1};
  int st = 0, rear = 1;
  step[r][c] = 1;
  wsearch[0] = r;
  wsearch[1] = c;
  while(st < rear){
    int thisx = wsearch[ st * 2 ];
    int thisy = wsearch[ st * 2 + 1 ];
    int thisv = step[thisx][thisy];
    for(int i = 0 ; i < 9 ; i++){
      int newx = thisx + derx[i];
      int newy = thisy + dery[i];
      if(newx >= 0 && newx  < R && newy >= 0 && newy < C && !step[newx][newy]){
        step[newx][newy] = thisv + 1;
        wsearch[ rear * 2 ] = newx ;
        wsearch[ rear * 2 + 1] = newy ;
        rear ++ ;
      }
    }
    st++;
  }
}
int minn(int v1,int v2){
  return v1<v2?v1:v2;
}
void knight(int r,int c){
  int derx[] = {-2,-2,-1,-1,1,1,2,2};
  int dery[] = {-1,1,-2,2,-2,2,-1,1};
  int st = 0, rear = 1;
  int i,j;
  for(i=0;i<R;i++)
    for(j=0;j<C;j++)
      knightstep[i][j] = 0;
  knightstep[r][c] = 1;
  wsearch[0] = r;
  wsearch[1] = c;
  while(st < rear){
    int thisx = wsearch[ st * 2 ];
    int thisy = wsearch[ st * 2 + 1 ];
    int thisv = knightstep[thisx][thisy];
    for(i = 0 ; i < 8 ; i++){
      int newx = thisx + derx[i];
      int newy = thisy + dery[i];
      if(newx >= 0 && newx  < R && newy >= 0 && newy < C && !knightstep[newx][newy]){
        knightstep[newx][newy] = thisv + 1;
        wsearch[ rear * 2 ] = newx ;
        wsearch[ rear * 2 + 1] = newy ;
        rear ++ ;
      }
    }
    st++;
  }
  for(i=0;i<R;i++)
    for(j=0;j<C;j++){
      if(knightstep[i][j] == 0)
        cntpage[i][j] = -1;
      if(cntpage[i][j] == -1)
        continue;
      cntpage[i][j] += knightstep[i][j] - 1;
    }

  st = 0;
  rear = 0;

  for(i=0;i<R;i++)
    for(j=0;j<C;j++){
      if(knightstep[i][j] != 0){
        bringking[i][j] = step[i][j] + knightstep[i][j] - 1;
        wsearch[rear * 2] = i;
        wsearch[rear * 2 + 1] = j;
        rear ++ ;
      }
    }
  while(st < rear){
    int thisx = wsearch[ st * 2 ];
    int thisy = wsearch[ st * 2 + 1 ];
    int thisv = bringking[thisx][thisy];
    for(i = 0 ; i < 8 ; i++){
      int newx = thisx + derx[i];
      int newy = thisy + dery[i];
      if(newx >= 0 && newx  < R && newy >= 0 && newy < C && bringking[newx][newy] > thisv + 1){
        bringking[newx][newy] = thisv + 1;
        wsearch[ rear * 2 ] = newx ;
        wsearch[ rear * 2 + 1] = newy ;
        rear ++ ;
      }
    }
    st++;
  }
  for(i=0;i<R;i++)
    for(j=0;j<C;j++)
      if(knightstep[i][j] != 0)
        minder[i][j] = minder[i][j] == -1 ?
          bringking[i][j] - knightstep[i][j]:
          minn(bringking[i][j] - knightstep[i][j],minder[i][j]);
}
int stepmin = 100000000;
void trystepcnt(){
  int i,j;
  for(i=0;i<R;i++)
    for(j=0;j<C;j++)
      if(cntpage[i][j] != -1){
        int newcnt = cntpage[i][j] + ((minder[i][j] == -1)?0:minder[i][j]);
        stepmin = stepmin < newcnt ? stepmin : newcnt ;
      }

}
int main(){
  inc>>R>>C;
  int i,j;
  for(i=0;i<R;i++)
    for(j=0;j<C;j++)
      minder[i][j] = -1;
  char c;
  int r;
  inc>>c>>r;
  king(r - 1, c - 'A');
  cout<<endl;
  cout<<"king:step[]="<<endl;
  for(i=0;i<R;i++){
    for(j=0;j<C;j++)
      cout<<step[i][j]<<" ";
    cout<<endl;
  }
  while(inc>>c>>r){
    knight(r - 1, c - 'A');
    // cout<<"knight"<<endl;
    // for(i=0;i<R;i++){
    //   for(j=0;j<C;j++)
    //     cout<<knightstep[i][j]<<" ";
    //   cout<<endl;
    // }
    // cout<<"cntpage"<<endl;
    // for(i=0;i<R;i++){
    //   for(j=0;j<C;j++)
    //     cout<<cntpage[i][j]<<" ";
    //   cout<<endl;
    // }
    // cout<<"bringking"<<endl;
    // for(i=0;i<R;i++){
    //   for(j=0;j<C;j++)
    //     cout<<bringking[i][j]<<" ";
    //   cout<<endl;
    // }
    // cout<<"minder"<<endl;
    // for(i=0;i<R;i++){
    //   for(j=0;j<C;j++)
    //     cout<< minder[i][j] <<" ";
    //   cout<<endl;
    // }
  }
  trystepcnt();
  outc << stepmin << endl;
  return 0;
}
/*
 * kuan sou for each knight
 * jisuan chu mei yi ge tu diff(bringking,normal)
 * min(i,j) = sum(normal) + min(der(i,j))
 * min = min(min(i,j))
 */
