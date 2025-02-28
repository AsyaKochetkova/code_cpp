#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int a, s = 0;
  std::vector<int> ans;

  for (int i = 0; i < 4; i++) {
    std::cin >> a;
    s += a;
    ans.push_back(a);
  }

  if (s > 1 && s < 5) {
    std::cout << 0;
    return 0;
  };
  if (s < 2) {
    std::cout << 1;
    return 0;
  };

  std::sort(ans.begin(), ans.end());

  if (ans[0] > 4) {
    std::cout << 4;
    return 0;
  };
  if (ans[0] + ans[1] > 4) {
    std::cout << 3;
    return 0;
  };
  if (ans[0] + ans[1] + ans[2] > 4) {
    std::cout << 2;
    return 0;
  };
  if (s > 4) {
    std::cout << 1;
    return 0;
  };
}