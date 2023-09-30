#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// advanced recursion problems

void permutations(string s, string ans) {
  if (s.length() == 0) {
    cout << ans << endl;
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    string ros = s.substr(0, i) + s.substr(i + 1);
    permutations(ros, ans + ch);
  }
}

int cntPath(int st, int en){
  if(st==en){
    return 1;
  }
  else if(st>en){
    return 0;
  }
  int res = 0;
  for(int i = 1;i<6;i++){
    res+=cntPath(st+i,en);
  }
  return res;
}

int cntMazePath(int n, int i, int j){
  if(i==n-1 && j==n-1){
    return 1;
  }
  else if(i>=n || j>=n) return 0;
  return cntMazePath(n, i+1, j)+cntMazePath(n, i, j+1);
}

int main() {

  // print all permutations of the string
  permutations("abc", "");

  //count the number of possible paths from start to end in horizontal boardgame
  cout<<cntPath(0, 3)<<endl;

  // count the number of possible paths in a maze without obstacles
  cout<<cntMazePath(3,0,0)<<endl;
  
}
