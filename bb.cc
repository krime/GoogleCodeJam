#include <iostream>
#include <cstring>

using namespace std;

#define N 10
#define M 10

int l[N][M];
int f[N][M];

bool find_edge_min(int&y,int&x,int n,int m) {
  bool fe=false;
  int mx=0;
  int my=0;
  // Column 1
  for (int i=0;i<n;i++)
    if (l[my][mx]>l[i][0]) {
      my=i;
      mx=0;
    } else if (l[my][mx]!=l[i][0]) fe=true;
  // Column 2
  for (int i=0;i<n;i++)
    if (l[my][mx]>l[i][m-1]) {
      my=i;
      mx=m-1;
    } else if (l[my][mx]!=l[i][m-1]) fe=true;
  // Row 1
  for (int i=0;i<m;i++)
    if (l[my][mx]>l[0][i]) {
      my=0;
      mx=i;
    } else if (l[my][mx]!=l[0][i]) fe=true;
  // Row 2
  for (int i=0;i<m;i++)
    if (l[my][mx]>l[n-1][i]) {
      my=n-1;
      mx=i;
    } else if (l[my][mx]!=l[n-1][i]) fe=true;
  x=mx;
  y=my;
  return fe;
}

bool colavail(int x,int n,bool&chk) {
  int c=l[0][x];
  int colalong=true;
  bool chked=f[0][x];
  for (int i=1;i<n;i++) {
    chked=chked&&f[i][x];
    if (c!=l[i][x]) {
      colalong=false;
      break;
    }
  }
  chk=chked;
  return colalong;
}

bool rowavail(int y,int m,bool&chk) {
  int c=l[y][0];
  int rowalong=true;
  bool chked=f[y][0];
  for (int i=1;i<m;i++) {
    chked=chked&&f[y][i];
    if (c!=l[y][i]) {
      rowalong=false;
      break;
    }
  }
  chk=chked;
  return rowalong;
}

bool fill_cross(int y,int x,int n,int m) {
  bool colchked=true;
  bool rowchked=true;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++)
      cout<<f[i][j];
    cout<<endl;
  }
  bool colchk=colavail(x,n,colchked);
  bool rowchk=rowavail(y,m,rowchked);
  if (colchked&&rowchked) return true;
  if (colchk) {
    for (int i=0;i<n;i++)
      f[i][x]=true;
    for (int i=0;i<n;i++) {
      if (i!=y)
        fill_cross(i,x,n,m);
    }
  }
  if (rowchk) {
    for (int i=0;i<m;i++)
      f[y][i]=true;
    for (int i=0;i<m;i++) {
      if (i!=x)
        fill_cross(y,i,n,m);
    }
  }
  return colchk||rowchk;
}

int main(void) {
  int t=0,n=0,m=0,tt=0,a=false,x=0,y=0,filled=0;
  cin>>t;
  tt=t;
  while (t--) {
    memset(l,0,sizeof(int)*N*M);
    memset(f,0,sizeof(int)*N*M);
    cout<<"Case #"<<tt-t<<": "<<endl;
    cin>>n>>m;
    if (n==1 || m==1) {
      cout<<"Yes"<<endl;
      continue;
    }
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        cin>>l[i][j];
      for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++)
          cout<<l[i][j];
        cout<<endl;
      }
      cout<<endl;
    while (find_edge_min(y,x,n,m)) {
      //cout<<"Found row:"<<y<<" and column:"<<x<<endl;
      memset(f,0,sizeof(int)*N*M);
      filled=fill_cross(y,x,n,m);
      for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
          if (f[i][j])
            l[i][j]++;
      for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++)
          cout<<l[i][j];
        cout<<endl;
      }
      cout<<endl;
      if (!filled) break;
    }
    if (filled) {
      int min=l[0][0];
      for (int i=1;i<n-1;i++) {
        for (int j=1;j<m-1;j++)
          if (min>l[i][j]) {
            min=l[i][j];
            break;
          }
        if (min!=l[0][0]) break;
      }
      if (min==l[0][0]) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    } else cout<<"No"<<endl;
  }
  return 0;
}
