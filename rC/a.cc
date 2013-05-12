#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define L 1000001

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
  string name;
  cin>>t;
  tt=t;
  while (t--) {
    name.clear();
    c=0;
    cout<<"Case #"<<tt-t<<": ";
    cin>>name>>n;
    l=name.size();
    string v=string(n,'1');
    //printf("%d\n",l);
    for (int i=0;i<l;i++) {
      if (name[i]=='a' ||
          name[i]=='e' ||
          name[i]=='i' ||
          name[i]=='o' ||
          name[i]=='u') name[i]='0';
      else name[i]='1';
    }
    for (int i=0;i<l;i++) {
      for (int j=i+n;j<=l;j++) {
        if (search(name.begin()+i,name.begin()+j,v.begin(),v.end())!=name.begin()+j) {
          c++;
        }
      }
    }
        //for (int k=i;k+n<=j;k++) {
        //  if (!strncmp(name+k,v,n)) {
        //         /*
    //         for (int x=i;x<j;x++)
    //           putchar(name[x]);
    //         puts("");
    //         */
    //         c++;
    //         break;
    //       }
    //     }
    //   }
    // }
    //printf("%s %d\n",name,n);
    
    //cout<<name<<' '<<n<<v<<endl;
    cout<<c<<endl;
  }
  return 0;
}
