#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int binarySearch(vector<int> v, int key){
  sort(v.begin(), v.end());
  int st=0, en=v.size()-1;
  int ind = -1;
  while(st<=en){
    int md = (en+st)/2;
    if(key<v[md]){
      en=md-1;
    }
    else if(key>v[md]){
      st=md+1;
    }
    else{
      ind = md;
      break;
    }
  }
  return ind;
}

int main() {
  vector<int> v = {5,7,32,6,4};
  int key = 32;
  cout<<binarySearch(v,key)<<endl;
}
