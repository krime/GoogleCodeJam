#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>

#define L 1000001

using namespace std;
string name;
//int b[L];

int main(void) {
  /*
    T 100
    Number of test case
    N L
    Number of consective consonants
    L 
    10^2 for small case
    10^6 for large case
    Length of name
  */
  int t,tt,n,l;
  long long s=0;
  int a0=0,a1=0;

  char conso[26]={0};
  memset(conso,1,sizeof(conso));
  
  conso['a'-'a']=
    conso['e'-'a']=
    conso['i'-'a']=
    conso['o'-'a']=
    conso['u'-'a']=0;
  
  cin>>t;
  tt=t;
  while (t--) {
    name.clear();
    cout<<"Case #"<<tt-t<<": ";
    cin>>name>>n;
    l=name.size();
    //memset(b,0,sizeof(b));
    vector<int> b=vector<int>(l);
    a1=a0=conso[name[0]-'a'];
    s=b[0]=a0*(n==1);
    for (int i=1;i<l;i++) {
      a1=conso[name[i]-'a']*(a0+1);
      a0=a1;
      if (a1>=n) b[i]=i-n+2;
      else b[i]=b[i-1];
      s+=b[i];
    }
    cout<<s<<endl;
    /*
    cout<<"[";
    for (int i=0;i<l;i++) cout<<' '<<a[i];
    cout<<" ]"<<endl;
    */
    //for (int i=0;i<l;i++) cout<<b[i]<<endl;
  }
  return 0;
}
