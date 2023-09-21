#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// number of subarrays = nC2 + n
// number of subsequence = 2^n

int kadane(int a[], int n){
  int cSum = 0, mxSum = INT64_MIN;
  for (int i = 0; i < n; i++) {
    cSum += a[i];
    if (cSum < 0)
      cSum = 0;
    mxSum = max(mxSum, cSum);
  }
  return mxSum;
}

bool pairSum(int a[], int n, int k){ // time complexity in of sorting
  // sort(a.begin(), a.end());
  int lo=0, hi=n-1;
  while(lo<hi){
    if(a[lo]+a[hi]==k){
      cout<<lo<<" "<<hi<<endl;
      return true;
    } 
    else if(a[lo]+a[hi]>k){
      hi--;
    }
    else{
      lo++;
    }
  }
  cout<<-1<<" "<<-1<<endl;
  return false;
}

int main() {
  const int n = 5;
  int a[n] = {-4, 1, 1, 2, 3};

  // maximum subarray sum - cumulative sum approach O(n^2)
  int csa[n + 1];
  csa[0] = 0;
  for (int i = 1; i <= n; i++) {
    csa[i] = csa[i - 1] + a[i - 1];
  }
  int mx = INT64_MIN;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 0; j < i; j++) {
      sum = csa[i] - csa[j];
      mx = max(mx, sum);
    }
  }
  cout << mx << endl;

  // maximum subarray sum - Kadane's algoritht O(n)
  int cSum = 0, mxSum = INT64_MIN;
  for (int i = 0; i < n; i++) {
    cSum += a[i];
    if (cSum < 0)
      cSum = 0;
    mxSum = max(mxSum, cSum);
  }
  cout << mxSum << endl;

  // maximum circular subarray sum
  int wrapSum, nonWrapSum = kadane(a,n);
  int totalSum = 0;
  for(int i = 0; i<n; i++){
    totalSum+=a[i];
    a[i]=-a[i];
  }
  wrapSum = totalSum - (- kadane(a,n));
  for(int i = 0; i<n; i++){
    a[i]=-a[i];
  }
  cout<<max(wrapSum,nonWrapSum)<<endl;

  // pair sum problem
  pairSum(a,n,4);
}
