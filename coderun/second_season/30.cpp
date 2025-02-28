#include <iostream>
#include <map>
#include <string>

int main() {
  int n, a = 0, b = 0, max = 0, m, prev_sum = 0;
  char c;
  std::string surname, max_surname;
  std::map<std::string, int> top;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> surname;
    top[surname] = 0;
  }

  std::cin >> m;

  for (int i = 0; i < m; i++) {
    std::cin >> a >> c >> b >> surname;

    top[surname] += a + b - prev_sum;

    prev_sum = a + b;

    if (top[surname] > max) {
      max = top[surname];
      max_surname = surname;
    }
    if (top[surname] == max && surname > max_surname) max_surname = surname;
  }

  std::cout << max_surname << " " << max << "\n";
}