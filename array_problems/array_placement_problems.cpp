#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// number of subarrays = nC2 + n
// number of subsequence = 2^n

int main() {
  int a[8] = {1,2,3,4,5,6,7,8};
  int n = 8;

  // find the arithmatic subarray of max length
  int pd = a[1]-a[0], curr = 2, ans = 2; 
  for (int i = 2; i<n; i++){
    if(pd == a[i]-a[i-1]){
      curr++;
    }
    else{
      pd = a[i]-a[i-1];
      curr=2;
    }
    ans = max(ans,curr);
  }
  cout<<ans<<endl;

  // record breaker
  int res = 0, pm = 0;
  for(int i = 0; i<n; i++){
    if(n==1){
      res=1;
      break;
    }
    else if(i==0 && a[i]>a[i+1]){
      res++;
      pm=a[i];
    }
    else if(i==n-1 && a[i]>pm){
      res++;
      pm=a[i];
    }
    else if(a[i]>pm && a[i]>a[i+1]){
      res++;
      pm=a[i];
    }
  }
  cout<<res<<endl;

  // first repeating element
  const int N = 1e6+2;
  int idx[N];
  for(int i = 0; i<N; i++) idx[i]=-1;
  int minIdx = 999999;
  for(int i = 0; i<n; i++){
    if(idx[a[i]]==-1){
      idx[a[i]]=i;
    }
    else{
      minIdx = min(minIdx, idx[a[i]]);
    }
  }
  if(minIdx!=999999)
    cout<<minIdx<<endl;
  else
    cout<<-1<<endl;

  // subarray with given sum in increasing array
  int s = 4;
  int st = 0, en = 0, currSum = a[0];
  while(currSum!=s && en<n){
    if(currSum<s){
      en++;
      currSum+=a[en];
    }
    else if(currSum>s){
      currSum-=a[st];
      st++;
    }
  }
  if(currSum==s){
    cout<<st<<":"<<en<<endl;
  }
  else{
    cout<<-1<<":"<<-1<<endl;
  }

  //smallest positive missing number
  // we can store negative indexs in an array by declearing 2*1e6+2 length
  const int C = 1e6+2;
  bool check[C];
  for(int i =0; i<C; i++) check[i]=false;
  for(int i = 0; i<n; i++){
    if(a[i]>=0){
      check[a[i]]=true;
    }
  }
  int result = -1;
  for(int i = 1; i<C; i++){
    if(!check[i]){
      result = i;
      break;
    }
  }
  cout<<result<<endl;
  
}
