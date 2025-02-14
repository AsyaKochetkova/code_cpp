/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing
order, and two integers m and n, representing the number of elements in nums1
and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be
stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the
last n elements are set to 0 and should be ignored. nums2 has a length of n.*/

#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<int> nums1 = {0}, nums2 = {1};
  int m = 0, n = 1;
  std::map<int, int>
      add;  // словарь в котором считаем количество каждого элемента

  // помещаем в словарь все элементы, учитывая внешнее ограничение на их
  // количество
  int i = 0;
  for (int& el : nums1) {
    if (i++ == m) break;
    if (add.count(el) == 0) {
      add[el] = 1;
    } else {
      add[el]++;
    }
  }

  for (int& el : nums2) {
    if (add.count(el) == 0) {
      add[el] = 1;
    } else {
      add[el]++;
    }
  }

  // запись из словаря в первый вектор всех элементов в нужных количествах
  i = 0;
  for (auto const& [num, count] : add) {
    for (int j = 0; j < count; j++) {
      nums1[i++] = num;
    }
  }

  for (int const& el : nums1) {
    std::cout << el << " ";
  }
  std::cout << "\n";

  return 0;
}