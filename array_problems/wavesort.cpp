#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// wave sort - time complexity: O(n)
void waveSort(int arr[], int n){
  int i = 1;
  while(i<n){
    if(arr[i]>arr[i-1]){
      int temp = arr[i];
      arr[i] = arr[i-1];
      arr[i-1] = temp;
    }
    if(arr[i]>arr[i+1] && i<=n-2){
      int temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
    }
    i+=2;
  }
}

int main() {

  int n = 7;
  int arr[] = {1,3,4,7,5,6,2};

  waveSort(arr, n);

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}
