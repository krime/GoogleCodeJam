#include <iostream>
#include <climits>

using namespace std;

#define N 1000000

int main(void) {
  /*
    T <= 100
    N <= 20 or 10^6
    |X|,Y <= 10^5
  */
  int t,tt,n,x,y;
  double p=0;
  cin>>t;
  tt=t;
  while (t--) {
    cin>>n>>x>>y;
    cout<<"Case #"<<tt-t<<": ";
    x=x>0?x:-x;
    int k=(x+y)/2;
    int sk=k*(2*k-1);
    int lk=sk+y;
    int uk=sk+2*k+1+y;
    if (n>=uk) p=1;
    else if (n<=lk) p=0;
    else {}
    cout<<p<<endl;
  }
  return 0;
}
