#define NUM 1000
int fa[NUM+10];
void initset(){
  rep(i,0,NUM){
    fa[i]=i;
  }
}
int getfa(int i){
  return fa[i] == i ? i : (fa[i] = getfa(fa[i]));
}
void linknode(int v1,int v2){
  fa[getfa(v1)] = getfa(v2);
}
