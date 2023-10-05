#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// dnf sort, 012 sort - time complexity: O(n)
void dnfSort(int arr[], int low, int mid, int high){
  while(mid<high){
    if(arr[mid]==0){
      int temp = arr[low];
      arr[low] = arr[mid];
      arr[mid] = temp;
      low++;
      mid++;
    }
    else if(arr[mid]==1){
      mid++;
    }
    else if(arr[mid]==2){
      int temp = arr[mid];
      arr[mid] = arr[high];
      arr[high] = temp;
      high--;
    }
    else{
      break;
    }
  }
}

int main() {

  int n = 8;
  int arr[] = {0,2,2,2,1,0,0,1};

  dnfSort(arr, 0, 0, n-1);

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}
