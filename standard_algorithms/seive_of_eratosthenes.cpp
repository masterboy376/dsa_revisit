#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void primeSieveOfErotasthenes(int n){
  int prime[100] = {0};
  for(int i = 2; i<=n; i++){
    if(prime[i]==0){
      for(int j = i*i; j<=n; j+=i){
        prime[j]=1;
      }
    }
  }
  for(int i = 2; i <=n;i++){
    if(prime[i]==0){
      cout<<i<<endl;
    }
  }
}

void primeFactorizationUsingSieve(int n){
  int spf[100]={0};
  for(int i=2;i<=n;i++){
    spf[i]=i;
  }
  for(int i = 2; i<=n; i++){
    if(spf[i]==i){
      for(int j = i*i; j<=n; j+=i){
        if(spf[j]==j)
          spf[j]=i;
      }
    }
  }
  if(n==1){
    cout<<1<<endl;
  }
  while(n!=1){
    cout<<spf[n]<<endl;
    n/=spf[n];
  }
}

int main() {
  // sieve of erotasthenes
  int n = 50;
  // primeSieveOfErotasthenes(n);

  // Prime factorization
  primeFactorizationUsingSieve(n);
}
