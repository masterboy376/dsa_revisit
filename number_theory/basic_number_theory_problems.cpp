#include <cmath>
#include <iostream>

int main() {
  // is prime
  int n;
  std::cin >> n;
  int flag = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (!(n % i)) {
      flag = 1;
      std::cout << "not a prime" << std::endl;
      break;
    }
  }
  if (!flag)
    std::cout << "a prime" << std::endl;

  // find rev
  std::cin >> n;
  int rev = 0;
  int r;
  while (n) {
    r = n % 10;
    rev = 10 * rev + r;
    n /= 10;
  }
  std::cout << rev << std::endl;

  // is armstrong num
  std::cin >> n;
  int res = 0, temp = n;
  while (temp) {
    r = temp % 10;
    res += pow(r, 3 / 1.0);
    temp /= 10;
  }
  if (n == res)
    std::cout << "an armstrong number" << std::endl;
  else
    std::cout << "not an armstrong number" << std::endl;
}
