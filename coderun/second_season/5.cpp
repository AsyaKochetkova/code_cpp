#include <iostream>
#include <vector>

int main() {
  int n, k, a, x;
  std::vector<int> stops, res;

  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    stops.push_back(a);
  }

  for (int i = 0; i < k; i++) {
    std::cin >> x;
    if (x > stops[0] && x < stops[n - 1]) {
      int j = 2, stop_num = n / j;
      while (x < stops[stop_num] || x > stops[stop_num + 1]) {
        j *= 2;
        if (x > stops[stop_num]) {
          if (n / j > 0)
            stop_num = stop_num + n / j;
          else
            stop_num++;
        };
        if (x < stops[stop_num]) {
          if (n / j > 0)
            stop_num = stop_num - n / j;
          else
            stop_num--;
        };
      }
      if (x == stops[stop_num]) {
        while (x == stops[stop_num]) stop_num--;
        stop_num++;
      };
      if (stops[stop_num + 1] - x < x - stops[stop_num]) stop_num++;
      std::cout << stop_num + 1 << " \n";
    } else {
      if (x <= stops[0])
        std::cout << 1 << " \n";
      else if (x == stops[n - 1]) {
        int h = 1;
        while (x == stops[n - h]) h++;
        std::cout << n - h + 2 << " \n";
      } else
        std::cout << n << " \n";
    }
  }

  return 0;
}