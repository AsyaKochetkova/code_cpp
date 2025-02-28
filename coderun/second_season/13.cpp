#include <iostream>
#include <map>
#include <string>

int main() {
  int l, max = 0;
  std::string str, p;
  std::map<std::string, int> list;

  std::getline(std::cin, str);
  l = str.length();
  if (l == 2) {
    std::cout << str << "\n";
    return 0;
  };
  for (int i = 0; i < l - 1; i++) {
    if (str.substr(i, 1) == " " || str.substr(i + 1, 1) == " ") continue;
    list[str.substr(i, 2)]++;
  }

  for (const auto& [sim, num] : list) {
    if (num >= max) {
      p = sim;
      max = num;
    };
  }

  std::cout << p << "\n";
}