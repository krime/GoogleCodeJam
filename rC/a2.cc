#include <iostream>
#include <sstream>

#include <iterator>

#include <cstring>

#define L 1000001
char name[L];

using namespace std;

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
    cout<<"Case #"<<tt-t<<": ";
    c=0;
    memset(name,0,sizeof(name)*sizeof(char));
    cin>>noskipws;

    istream_iterator<char> isr=istream_iterator<char>(cin);
    istream_iterator<char> eof;
    
    for (int i=0;*isr!=' ';i++) {
      name[i]=*isr++;
      cout<<name[i];
    }
  }
  return 0;
}
