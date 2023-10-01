#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// dificult recursion problems

int tiling(int n) { // similar to fibonacci
  if (n == 1)
    return 1;
  if (n == 0)
    return 0;
  return tiling(n - 1) + tiling(n - 2);
}

int friendsPairing(int n) {
  if (n == 0 || n == 1 || n == 2)
    return n;
  return friendsPairing(n - 1) + friendsPairing(n - 2) * (n - 1);
}

int knapsack01(int v[], int wt[], int n, int w) {
  if (n == 0 || w == 0)
    return 0;
  if (wt[n - 1] > w)
    return knapsack01(v, wt, n - 1, w);
  return max(knapsack01(v, wt, n - 1, w - wt[n - 1]) + v[n - 1],
             knapsack01(v, wt, n - 1, w));
}

int main() {

  // tiling ways
  cout << tiling(4) << endl;

  // friends pairing
  cout << friendsPairing(4) << endl;

  // 0-1 knapsack
  int v[] = {100, 50, 150};
  int wt[] = {10, 20, 30};
  cout << knapsack01(v, wt, 3, 50) << endl;
}
