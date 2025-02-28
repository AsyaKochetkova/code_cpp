#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int n;
  long long int res = 0;
  std::string str, stl, x, y;
  std::map<int, int> classes;
  std::vector<char> list{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  std::getline(std::cin, stl);
  std::getline(std::cin, str);
  std::istringstream SS(str);
  while (SS >> x) {
    int mem = 0;

    for (char s : x) {
      switch (s) {
        case '1':
          mem |= 0b001000000000;
          break;
        case '2':
          mem |= 0b000100000000;
          break;
        case '3':
          mem |= 0b000010000000;
          break;
        case '4':
          mem |= 0b000001000000;
          break;
        case '5':
          mem |= 0b000000100000;
          break;
        case '6':
          mem |= 0b000000010000;
          break;
        case '7':
          mem |= 0b000000001000;
          break;
        case '8':
          mem |= 0b000000000100;
          break;
        case '9':
          mem |= 0b000000000010;
          break;
        case '0':
          mem |= 0b000000000001;
          break;
      }
    }

    for (const auto& [word, num] : classes) {
      if (word & mem) res += num;
    }
    if (classes.count(mem) == 1)
      classes[mem]++;
    else
      classes.insert({mem, 1});
  }

  std::cout << res << "\n";
}