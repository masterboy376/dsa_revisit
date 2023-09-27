#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int divisible(int n, int a, int b){
  int c1 = n/a;
  int c2 = n/b;
  int c3 = n/(a*b);
  return c1+c2-c3;
}

int gcdByEuclidAlgorithm(int m, int n){
  while(n){
    int rem = m%n;
    m=n;
    n = rem;
  }
  return m;
}

int main() {
  // Inclusion exclusion principle - set theory

  int n,a,b;
  cin>>n>>a>>b;

  // total numbers divisible by a or b;
  cout<<divisible(n,a,b)<<endl;

  // Euclid algorithm to find GCD - HCF
  // lets say we have to find gcd of m,n
  // let m%n = p
  // now note that gcd for p,n is same as gcd of m,n
  int x,y;
  cin>>x>>y;
  cout<<gcdByEuclidAlgorithm(x,y)<<endl;
}
