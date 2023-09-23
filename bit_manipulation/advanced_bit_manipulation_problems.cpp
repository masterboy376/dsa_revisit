#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int unique(int a[], int n) {
  int xorSum = 0;
  for (int i = 0; i < n; i++) {
    xorSum = xorSum ^ a[i];
  }
  return xorSum;
}

void unique2(int a[], int n) {
  int xorSum = 0;
  for (int i = 0; i < n; i++) {
    xorSum = xorSum ^ a[i];
  }
  int setbit = 0, pos = 0;
  int tempXor = xorSum;
  while (setbit != 1) {
    setbit = xorSum & 1;
    pos++;
    xorSum = xorSum >> 1;
  }
  int newXor = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] & (1 << (pos - 1))) {
      newXor = newXor ^ a[i];
    }
  }
  cout << newXor << ", " << (tempXor ^ newXor) << endl;
}

int unique3(int a[], int n) {
  int res = 0;
  for (int i = 0; i < 64; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) { // get bit
        sum++;
      }
    }
    if (sum % 3) {
      res = res | (1 << i); // set bit
    }
  }
  return res;
}

int main() {
  // find unique number in an array where all numbers except one, are present
  // twice.
  int a_p1[7] = {2, 4, 6, 3, 2, 4, 6};
  int n_p1 = 7;
  cout << unique(a_p1, n_p1) << endl;

  // find 2 unique numbers in an array where all numbers except two, are present
  // twice
  int a_p2[8] = {2, 4, 6, 3, 2, 5, 4, 6};
  int n_p2 = 8;
  unique2(a_p2, n_p2);

  // find a unique numbers in an array where all numbers except one, are present
  // thrice
  int a_p3[10] = {1, 3, 2, 3, 4, 2, 1, 1, 3, 2};
  int n_p3 = 10;
  cout << unique3(a_p3, n_p3) << endl;
}
