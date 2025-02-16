/*Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {5};
  int target = -5;
  int l = 0, r = nums.size() - 1;

  while (l < r) {
    int avg = (l + r) / 2;
    if (r - l == 1) {
      if (nums[r] == target) {
        std::cout << r << "\n";
        return 0;
      }
      if (nums[l] == target) {
        std::cout << l << "\n";
        return 0;
      }
      std::cout << "-1\n";
      return 0;
    }
    if (nums[avg] > target) {
      r = avg;
    }
    if (nums[avg] == target) {
      std::cout << avg << "\n";
      return 0;
    }
    if (nums[avg] < target) {
      l = avg;
    }
  }

  if (nums[l] == target) {
    std::cout << l << "\n";
    return 0;
  }
  std::cout << "-1\n";
  return 0;
}