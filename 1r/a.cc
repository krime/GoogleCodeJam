#include <iostream>
#include <cstdlib>
#include <cstring>

#define N 100

using namespace std;

int cp(const void*a,const void*b) {
  return *(int*)a-*(int*)b;
}

int main(void) {
  int t,a,n;
  int m[N];
  cin>>t;
  int tt=t;
  while (tt--) {
    cout << "Case #"<<t-tt<<": ";
    cin>>a>>n;
    memset(m,0,sizeof m);
    for (int i=0;i<n;i++) cin>>m[i];
    
    qsort(m,n,sizeof m[0],cp);
    /*
    cout<<a<<' '<<n<<endl;
    cout<<"[";
    for (int i=0;i<n;i++) cout<<' '<<m[i];
    cout<<" ]"<<endl;
    */
    int x=a;
    int nm=0;
    for (int i=0;i<n;i++) {
      //int* s=(int*)bsearch(&x,m+i,n-i,sizeof m[0],cp);
      //cout<<*s<<endl;
      if (x>m[i]) {
        x+=m[i];
      } else {
        int j=0;
        int x0=x;
        while (x0<=m[i]&&x0!=1) {
          x0+=x0-1;
          j++;
        }
        //cout<<x0<<' '<<j<<' '<<n-i<<endl;
        if (j<n-i&&j!=0) {
          nm+=j;
          x=x0+m[i];
        }
        else {
          nm+=n-i;
          break;
        }
      }
    }
    if (nm<n)
      cout<<nm<<endl;
    else cout<<n<<endl;
    //    cout << endl;
  }
  return 0;
}
