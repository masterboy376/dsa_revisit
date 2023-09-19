#include <cmath>
#include <iostream>

int binaryToDecimal(int n) {
  int ans = 0;
  int x = 1;
  while (n) {
    int last = n % 10;
    n /= 10;
    ans += x * last;
    x *= 2;
  }
  return ans;
}

int octalToDecimal(int n) {
  int ans = 0;
  int x = 1;
  while (n) {
    int last = n % 10;
    n /= 10;
    ans += x * last;
    x *= 8;
  }
  return ans;
}

int hexToDecimal(std::string n) {
  int len = n.size();
  int ans = 0;
  int x = 1;
  for (int i = len - 1; i >= 0; i--) {
    if (n[i] >= '0' && n[i] <= '9') {
      ans += x * (n[i] - 48);
      x *= 16;
    } else if (n[i] >= 'A' && n[i] <= 'F') {
      ans += x * (n[i] - 55);
      x *= 16;
    }
  }
  return ans;
}

std::string revStr(std::string s) {
  int len = s.size();
  std::string str;
  for (int i = len - 1; i >= 0; i--) {
    str += s[i];
  }
  return str;
}

std::string decToBinary(int n) {
  std::string str;
  while (n) {
    if (n & 1)
      str += '1';
    else
      str += '0';
    n >>= 1;
  }
  return revStr(str);
}

std::string decToOctal(int n) {
  std::string str;
  int x = 1;
  while(x<=n)
    x*=8;
  x/=8;
  while(n){
    int curr = n/x;
    str+=('0'+curr);
    n%=x;
    x/=8;
  }
  return str;
}

std::string decToHex(int n) {
  std::string str;
  int x = 1;
  while(x<=n)
    x*=16;
  x/=16;
  while(n){
    int curr = n/x;
    if(curr<=9)
      str+=('0'+curr);
    else if(curr>=10 && curr<=15){
      str+=('A'+(curr-10));
    }
    n%=x;
    x/=16;
  }
  return str;
}

int main() {
  std::cout << binaryToDecimal(111) << std::endl;
  std::cout << octalToDecimal(144) << std::endl;
  std::cout << hexToDecimal("1A") << std::endl;
  std::cout << decToBinary(6) << std::endl;
  std::cout << decToOctal(100) << std::endl;
  std::cout << decToHex(26) << std::endl;
}
