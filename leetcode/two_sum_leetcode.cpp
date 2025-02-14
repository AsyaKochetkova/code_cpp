/*Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order */

#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<int> nums = {2, 3, -1, 2};
  std::map<int, int>
      add_set;  // для хранения пройденных элементов и их индексов
  std::vector<int> res;  // вектор для ответа
  int target = 2;

  // во время прохода по вектору для очередного элемента nums[i] поверяем
  // наличие его парного элемента target - nums[i] в словаре
  for (int i = 0;; i++) {
    // если есть парный элемент, то добавляем в вектор ответа индекс пары и
    // индекс текущего элемента
    if (add_set.count(target - nums[i]) == 1) {
      res.push_back(add_set[target - nums[i]]);
      res.push_back(i);
      break;
    }
    // добавляем элемент и его индекс в словарь
    else {
      add_set[nums[i]] = i;
    }
  }

  std::cout << res[0] << " " << res[1] << "\n";
  return 0;
}