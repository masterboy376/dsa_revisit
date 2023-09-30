#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// basic recursion problems

string reverse(string s) {
  if (s.length() == 0)
    return "";
  string newS = "";
  string ros = s.substr(1);
  newS += reverse(ros);
  newS += s[0];
  return newS;
}

string replacePI(string s) {
  if (s.length() == 0)
    return "";
  string newS = "";
  if (s[0] == 'p' && s[1] == 'i') {
    newS += "3.14";
    newS += replacePI(s.substr(2));
  } else {
    newS += s[0];
    newS += replacePI(s.substr(1));
  }
  return newS;
}

void towerOfHanoi(int n, char src, char dest, char helper) {
  if (n == 0) {
    return;
  }
  towerOfHanoi(n - 1, src, helper, dest);
  cout << "move from " << src << " to " << dest << endl;
  towerOfHanoi(n - 1, helper, dest, src);
}

string removeDuplicates(string s) {
  if (s.length() == 0)
    return "";
  string newS = "";
  string ros = s.substr(1);
  string transformedRos = removeDuplicates(ros);
  if (s[0] == transformedRos[0]) {
    newS += transformedRos;
  } else {
    newS += s[0] + transformedRos;
  }
  return newS;
}

string moveXToEnd(string s) {
  if (s.length() == 0)
    return "";
  string res = moveXToEnd(s.substr(1));
  if (s[0] == 'x') {
    return res + s[0];
  } else {
    return s[0] + res;
  }
}

void allSubstrings(string s, string ans) {
  if (s.length() == 0) {
    cout << ans << endl;
    return;
  }

  char ch = s[0];
  string ros = s.substr(1);

  allSubstrings(ros, ans);
  allSubstrings(ros, ans + ch);
}

void allSubstringsWithAscii(string s, string ans) {
  if (s.length() == 0) {
    cout << ans << endl;
    return;
  }

  char ch = s[0];
  int code = ch;
  string ros = s.substr(1);

  allSubstringsWithAscii(ros, ans);
  allSubstringsWithAscii(ros, ans + ch);
  allSubstringsWithAscii(ros, ans + to_string(code));
}

string keypadArr[] = {"", "./", "abc","def","ghi","jkl","mno","pqrs","tuv","vwxyz"};
void keypad(string s, string ans){
  if (s.length() == 0) {
    cout << ans << endl;
    return;
  }
  char ch = s[0];
  string code = keypadArr[ch-'0'];
  string ros = s.substr(1);

  for(int i = 0; i<code.length(); i++){
    keypad(ros,ans+code[i]);
  }
}

int main() {

  // reverse a string using recursion
  cout << reverse("binod") << endl;

  // replace pi string using recursion
  cout << replacePI("pdpigsgdfsspfsfifspfipi") << endl;

  // tower of hanoi
  towerOfHanoi(4, 'A', 'B', 'C');

  // remove all duplicates from string
  cout << removeDuplicates("aaaabbbbbccccddeeef") << endl;

  // move all x to end of the string
  cout << moveXToEnd("axjdfkjxnksxnkjxxxnfdjkfxxx") << endl;

  // genrate all substrings - we will constantly include and exclude each
  // character
  allSubstrings("abc", "");

  // genrate all substrings with ascii - we will constantly include and exclude
  // each character
  allSubstringsWithAscii("abc", "");

  // print all possible words from phone digits
  keypad("23","");
}
