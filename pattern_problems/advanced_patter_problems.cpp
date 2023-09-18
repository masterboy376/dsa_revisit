#include <iostream>

int main() {
  int n;
  std::cin >> n;

  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= i; j++) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      (i + j) % 2 ? std::cout << 0 << " " : std::cout << 1 << " ";
    }
    std::cout << std::endl;
  }

  for (int i = n; i > 0; i--) {
    for (int j = 1; j < i; j++) {
      std::cout << " ";
    }
    for (int j = 1; j <= n; j++) {
      std::cout << "*"
                << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      std::cout << " ";
    }
    for (int j = 1; j <= i; j++) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      std::cout << "  ";
    }
    for (int j = i; j >= 1; j--) {
      std::cout << j << " ";
    }
    for (int j = 2; j <= i; j++) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++) {
      std::cout << "  ";
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      std::cout << "*"
                << " ";
    }
    std::cout << std::endl;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n - i; j++) {
      std::cout << "  ";
    }
    for (int j = 1; j <= 2 * i - 1; j++) {
      std::cout << "*"
                << " ";
    }
    std::cout << std::endl;
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) {
      if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0)) {
        std::cout << "*"
                  << " ";
      } else {
        std::cout << " "
                  << " ";
      }
    }
    std::cout << std::endl;
  }
}
