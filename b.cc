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
  bool filled=true;
  bool colchk=false;
  bool rowchk=false;
  if (!f[y][x]) {
    f[y][x]=true;
    // Column check
    if (y>0  &&l[y-1][x]==l[y][x]) {
      //cout<<"Check col upwards"<<endl;
      for (int i=0;i<n;i++)
        if (i!=y) {
          if (l[i][x]!=l[y][x])
            return false;
          else filled=filled&&fill_cross(i,x,n,m);
        }
      colchk=true;
    }
    if (!colchk) {
      if (y<n-1&&l[y+1][x]==l[y][x]) {
        //cout<<"Check col downwards"<<endl;
        for (int i=0;i<n;i++)
          if (i!=y) {
            if (l[i][x]!=l[y][x])
              return false;
            else filled=filled&&fill_cross(i,x,n,m);
          }
        colchk=true;
      }
    }
    // Row check
    if (x>0  &&l[y][x-1]==l[y][x]) {
      //cout<<"Check row leftwards"<<endl;
      for (int i=0;i<m;i++)
        if (i!=x) {
          if (l[y][i]!=l[y][x])
            return false;
          else filled=filled&&fill_cross(y,i,n,m);
        }
      rowchk=true;
    }
    if (!rowchk) {
      if (x<m-1&&l[y][x+1]==l[y][x]) {
        //cout<<"Check row rightwards"<<endl;
        for (int i=0;i<m;i++)
          if (i!=x) {
            if (l[y][i]!=l[y][x])
              return false;
            else filled=filled&&fill_cross(y,i,n,m);
          }
        rowchk=true;
      }
    }
    // l[y][x]++;
  } else filled=true;
  return filled;
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
