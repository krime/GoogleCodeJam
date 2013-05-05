#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<climits>

int mote[110];
int f[110];
int cp(const void*a,const void*b) {
  return *(int*)a-*(int*)b;
}
int GetValue()
{
  int size, num,i,currentsize,step,min;
  bool isone;
  scanf("%d %d",&size, &num);
  for(i=1;i<=num;++i) scanf("%d",mote+i);
  qsort(mote+1,num,sizeof mote[0],cp);
  mote[0]=0;
  f[0]=0;
  currentsize = size;
  for(i=1;i<=num;++i) {
    if (currentsize>mote[i]) {
      currentsize+=mote[i];
      f[i]= f[i-1];
    } else {
      step =0;
      isone = false;
      while(currentsize<=mote[i]) {
        if (currentsize==1) {
          isone = true;
          break;
        }
        currentsize+=currentsize-1;
        step++;
      }
      if (isone) {
        f[i]=INT_MAX;
      } else {
        if (f[i-1]==INT_MAX)
          f[i]=f[i-1];
        else
          f[i]=f[i-1]+step;
      }
    }
  }
  min=INT_MAX;
  for(i=0;i<=num;++i) {
    if ((f[i]!=INT_MAX) && (f[i]+num-i<min))
      min=f[i]+num-i;
  }
  return min;
}
int main(){
  int i,a,b,c,t;
  scanf("%d",&t);
  for(i=1;i<=t;++i)
    printf("Case #%d: %d\n",i, GetValue());
  //scanf("%d",&t);
}
