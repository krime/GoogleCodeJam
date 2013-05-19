#include <iostream>
#include <string>
#include <cstring>

#define L 1000001

using namespace std;
string name;

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
  int a0=0,a1=0,b=0;

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
    a1=a0=conso[name[0]-'a'];
    s=b=a0*(n==1);
    for (int i=1;i<l;i++) {
      a0=a1=conso[name[i]-'a']*(a0+1);
      if (a1>=n) b=i-n+2;
      s+=b;
    }
    cout<<s<<endl;
  }
  return 0;
}
