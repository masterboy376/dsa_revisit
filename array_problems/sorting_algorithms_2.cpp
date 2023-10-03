#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// recursive sorting algorithms and some more sorting algorithms

// merge sort - time complexity = O(nlogn)
// divide and conqure
void merge(int arr[], int l, int mid, int r){
  int n1 = mid-l+1;
  int n2 = r-mid;
  int a[n1];
  int b[n2];
  for(int i = 0; i<n1; i++){
    a[i]=arr[l+i];
  }
  for(int i = 0; i<n2; i++){
    b[i]=arr[mid+1+i];
  }
  int i = 0, j=0, k = l;
  while(i<n1 && j<n2){
    if(a[i]<b[j]){
      arr[k]=a[i];
      i++;
      k++;
    }
    else{
      arr[k]=b[j];
      j++;
      k++;
    }
  }
  while(i<n1){
    arr[k]=a[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k]=b[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int r){
  if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr,l,mid,r);
  }
}

// quick sort - time complexity = O(nlogn)
// again divide and conqure
int partition(int arr[], int l, int r){
  int pivot = arr[r];
  int i = l-1;
  for(int j = i+1;j<r;j++){
    if(arr[j]<pivot){
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i+1];
  arr[i+1] = arr[r];
  arr[r] = temp;
  return i+1;
}
void quickSort(int arr[], int l, int r){
  if(l<r){
    int pi = partition(arr, l, r);
    quickSort(arr, l, pi-1);
    quickSort(arr,pi+1,r);
  }
}

int main() {

  int n=9;
  int arr[] = {4,5,6,5,2,2,3,-1,0};

  mergeSort(arr,0,n-1);
  quickSort(arr,0,n-1);

  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
}
