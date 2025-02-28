#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string a, b, c, res;
  int a_ind = 0, b_ind = 0, c_ind = 0, a_s, b_s, c_s, res_s;
  bool res_bool = true;
  std::cin >> a >> b >> c;

  while (a.length() + b.length() + c.length() > 0) {
    if (a[0] != b[0] || b[0] != c[0] || a[0] != c[0]) {
      res_bool = false;
      break;
    } else {
      a_ind = 0;
      b_ind = 0;
      c_ind = 0;
      a_s = 0;
      b_s = 0;
      c_s = 0;
      while (a[a_ind] == a[0] && a_ind < a.length()) {
        a_ind++;
        a_s++;
      }
      while (b[b_ind] == b[0] && b_ind < b.length()) {
        b_ind++;
        b_s++;
      }
      while (c[c_ind] == c[0] && c_ind < c.length()) {
        c_ind++;
        c_s++;
      }
      int min = a_ind, max = a_ind;
      if (b_ind < min) min = b_ind;
      if (b_ind > max) max = b_ind;
      if (c_ind < min) min = c_ind;
      if (c_ind > max) max = c_ind;

      res += std::string(a_ind + b_ind + c_ind - min - max, a[0]);
      a = a.substr(a_ind);
      b = b.substr(b_ind);
      c = c.substr(c_ind);
    }
  }

  if (res_bool)
    std::cout << res << "\n";
  else
    std::cout << "IMPOSSIBLE"
              << "\n";
}