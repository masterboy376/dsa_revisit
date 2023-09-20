#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// selection sort: time: O(n*n), space: O(1)
// find the min element in unsorted array and swap it with element at begining
void selectionSort(int *arr, int n){
  for(int i = 0; i<n-1; i++){
    for(int j = i+1; j<n; j++){
      if(arr[j]<arr[i]){
        int temp = arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }
  }
}

// bubble sort: time: O(n*n), space: O(1)
// repeatedly swap two adjacent element if in wrong order
void bubbleSort(int *arr, int n){
  int counter = 1;
  while(counter<n){
    for(int i = 0; i<n-counter; i++){
      if(arr[i]>arr[i+1]){
        int temp = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
    }
    counter++;
  }
}

// insertion sort: time: O(n*n), space: O(1)
// insert an element from unsorted array to its correct position in sorted array
void insertionSort(int *arr, int n){
  for(int i = 1; i<n; i++){
    int curr = arr[i];
    int j = i-1;
    while(arr[j]>curr && j>=0){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=curr;
  }
}

int main() {
  const int n = 7;
  int arr[n] = {4,2,4,2,8,6,0};

  // selectionSort(arr,n);
  // bubbleSort(arr,n);
  insertionSort(arr,n);
  
  for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
  cout<<endl;
}
