#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// recursive sorting algorithms and some more sorting algorithms

// count sort - time complexity: O(n)
void countSort(int arr[], int n){
  int k = arr[0];
  for(int i = 0; i<n; i++){
    k = max(k,arr[i]);
  }
  const int size = k+1;
  int count[100] = {0};
  for(int i = 0; i<n; i++){
    count[arr[i]]++;
  }
  for(int i  = 1; i<=k; i++){
    count[i] += count[i-1];
  }
  int output[n];
  for(int i = n-1; i>=0; i--){
    output[--count[arr[i]]] = arr[i];
  }
  for(int i = 0 ; i<n; i++){
    arr[i]=output[i];
  }
}

int main() {

  int n = 7;
  int arr[] = {1,2,3,6,3,5,4};

  countSort(arr,n);

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}
