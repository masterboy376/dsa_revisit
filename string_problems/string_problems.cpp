#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // change string case
  string a = "dsgjnsdkfjfjJDNDNKDKDdf";
  transform(a.begin(), a.end(), a.begin(), ::toupper);
  cout<<a<<endl;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  cout<<a<<endl;

  // make biggest number
  a = "12345";
  sort(a.begin(), a.end(), greater<int>());
  cout<<a<<endl;

  // output most frequent number
  a = "dgsdkgkjg";
  int freq[26];
  for(int i = 0; i<26; i++) freq[i]=0;
  for(int i = 0; i<a.size(); i++){
    freq[a[i]-'a']++;
  }
  char ans = 'a';
  int mxf = 0;
  for(int i =0; i<26; i++){
    if(freq[i]>mxf){
      mxf = freq[i];
      ans = i+'a';
    }
  }
  cout<<ans<<":"<<mxf<<endl;
  
}
