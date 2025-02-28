#include <iostream>

int main() {
  int a, b, n;
  std::cin >> a >> b >> n;
  if (b % n > 0)
    b = b / n + 1;
  else
    b = b / n;
  if (a > b)
    std::cout << "Yes";
  else
    std::cout << "No";
  return 0;
}