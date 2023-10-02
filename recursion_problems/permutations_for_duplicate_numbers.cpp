#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// all possible permutaions for duplicate element
// total permutations: n!/m!*p!, m,p are same element

void helper(vector<int> a, vector<vector<int>> &ans, int idx) {
  if (idx == a.size()) {
    ans.push_back(a);
    return;
  }
  for (int i = idx; i < a.size(); i++) {
    if (i != idx && a[i] == a[idx])
      continue;
    swap(a[i], a[idx]);
    helper(a, ans, idx + 1);
    // note : 2nd swap os not neccesary as the vec a is taken as copy rather than as a reference
  }
}

vector<vector<int>> permute(vector<int> a) {
  sort(a.begin(), a.end());
  vector<vector<int>> ans;
  helper(a, ans, 0);
  return ans;
}

int main() {

  // using recursion - we can use sets but to optimize we have to avoid duplicate cases
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<vector<int>> ans = permute(a);
  for (auto v : ans) {
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }
}
