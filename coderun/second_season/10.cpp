#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main() {
  int n = 0, day = 0, stress = 0, last_day = 0;
  long long int full_stress = 0;
  std::vector<std::pair<int, int>> task_list;
  std::set<int> work_days;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> day >> stress;
    if (last_day < day) last_day = day;
    full_stress += stress;
    task_list.push_back({-stress, -day});
  }
  std::sort(task_list.begin(), task_list.end());

  for (int i = 1; i <= n; i++) work_days.insert(-i);

  for (auto [s, d] : task_list) {
    if (work_days.lower_bound(d) == work_days.end()) {
      work_days.erase(*work_days.begin());
    } else {
      work_days.erase(*work_days.lower_bound(d));
      full_stress += s;
    }
  }

  std::cout << full_stress << "\n";
}