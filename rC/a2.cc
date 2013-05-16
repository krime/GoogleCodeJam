#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
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
  int c=0;
  const char alpha[26]={
    0,1,1,1,0,1,1,
    1,0,1,1,1,1,1,
    0,1,1,  1,1,1,
    0,1,1,  1,1,1
  };
  cin>>t;
  tt=t;
  while (t--) {
    name.clear();
    c=0;
    cout<<"Case #"<<tt-t<<": ";
    cin>>name>>n;
    l=name.size();
    string v=string(n,'1');
    for (int i=0;i<l;i++)
      name[i]=alpha[name[i]-'a']+'0';
    for (int i=0;i<l;i++) {
      for (int j=i+n;j<=l;j++) {
        if (search(name.begin()+i,name.begin()+j,v.begin(),v.end())!=name.begin()+j) {
          c++;
        }
      }
    }
    cout<<name<<' '<<n<<v<<endl;
    cout<<c<<endl;
  }
  return 0;
}
