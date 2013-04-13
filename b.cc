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

bool fill_cross(int y,int x,int n,int m) {
  memset(f,0,sizeof(int)*N*M);
  bool fill=true;
  
  return 0;
}

int main(void) {
  int t=0,n=0,m=0,tt=0,a=false,x=0,y=0;
  cin>>t;
  tt=t;
  while (t--) {
    memset(l,0,sizeof(int)*N*M);
    memset(f,0,sizeof(int)*N*M);
    cout<<"Case #"<<tt-t<<": ";
    cin>>n>>m;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        cin>>l[i][j];
    while (find_edge_min(y,x,n,m))
      if (!fill_cross(y,x,n,m))
        break;
  }
  return 0;
}
