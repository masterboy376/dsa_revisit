#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool isPowerOf2(int n){
  // n = 6 = (0110)
  // n-1 = 5 = (0101)
  return (n && !(n & (n-1)));
}

int cntOnes(int n){
  int cnt = 0;
  while(n){
    n = n & (n-1);
    cnt++;
  }
  return cnt;
}

void subsets(int a[], int n){
  for(int i = 0; i<(1<<n); i++){
    cout<<"{ ";
    for(int j = 0; j<n; j++){
      if( i & (1<<j)){
        cout<<a[j]<<", ";
      }
    }
    cout<<"}"<<endl;
  }
}

int main() {
  int n = 7;
  
  // program to check if a given number is power of 2 or not
  if(isPowerOf2(n)) cout<<"power of 2"<<endl;
  else cout<<"not the power on 2"<<endl;

  // count the number of ones in binary representation
  cout<<cntOnes(n)<<endl;

  // write all possible subsets of a set
  int a[3] = {1,2,3};
  subsets(a,3);
  
}
