#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// all possible permutaions for distinct element
// total permutations: n!

vector<vector<int>> ans;
vector<vector<int>> ans1;

void permute(vector<int> &a, int idx){
  if(idx == a.size()){
    ans.push_back(a);
    return;
  }
  for(int i = idx; i<a.size(); i++){
    swap(a[i],a[idx]);
    permute(a,idx+1);
    swap(a[i],a[idx]);
  }
}

int main() {

  // using recursion
  int n;cin>>n;
  vector<int> a(n);
  for(auto &i : a){
    cin>>i;
  }
  permute(a,0);
  for(auto v: ans){
    for(auto i : v) 
      cout<<i<<" ";
    cout<<endl;
  }

  // using stl lib
  int n1;cin>>n1;
  vector<int> a1(n);
  for(auto &i : a1){
    cin>>i;
  }
  sort(a1.begin(), a1.end());
  do{
    ans1.push_back(a1);
  } while(next_permutation(a1.begin(), a1.end()));
  for(auto v: ans1){
    for(auto i : v) 
      cout<<i<<" ";
    cout<<endl;
  }
  
}
