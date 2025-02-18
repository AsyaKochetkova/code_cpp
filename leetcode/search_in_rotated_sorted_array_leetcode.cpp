/*There is an integer array nums sorted in ascending order (with distinct
values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k],
nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
[4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

// Проверка монотонности последовательности
// Если нет сдвига, то начальные границы бинпоиска : l = 0, r = nums.size()-1
// Если есть сдвиг, то найдем границу, разрыв монотонности, запустим алгоритм
// бинпоиска, но остановкой станет условие lb-rb == 1, потому что nums[lb] >
// nums[rb], и при таком условии nums[rb] - минимальный элемент, граница. Делаем
// проверку принадлежности target к правой подпоследовательности или левой
// target >= nums[0], и задаем соответственные начальные граница бинпоиска: l =
// 0, r = lb или l = rb. r = nums.size()-1

#include <iostream>
#include <vector>

int main() {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 1;

  int l, r, lb, rb;

  if (nums.size() == 0) {
    std::cout << "size = 0\n";
    std::cout << "-1\n";
    return 0;
  }

  if (nums.size() == 1) {
    std::cout << "size = 1\n";
    nums[0] == target ? std::cout << "0\n" : std::cout << "-1\n";
    return 0;
  }

  if (nums[0] < nums[-1]) {
    std::cout << " f < l";
    l = 0;
    r = nums.size() - 1;
  } else {
    lb = 0;
    rb = nums.size() - 1;

    while (rb - lb > 1) {
      int avr = (lb + rb) / 2;
      if (nums[avr] > nums[rb]) lb = avr;
      if (nums[avr] == nums[rb]) break;
      if (nums[avr] < nums[rb]) rb = avr;
      std::cout << "lb = " << lb << ", rb = " << rb << "\n";
    }
    if (nums[0] > target) {
      l = rb;
      r = nums.size() - 1;
    } else {
      l = 0;
      r = rb - 1;
    }
  }

  std::cout << "l = " << l << ", r = " << r << "\n";

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
