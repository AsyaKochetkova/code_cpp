/*Given two strings s and t, return true if t is an anagram  of s, and false
 * otherwise.*/

#include <iostream>
#include <map>
#include <string>

int main() {
  std::string s = "rat", t = "car";
  std::map<char, int> char_list;
  bool ans = true;

  // первичная проверка на совпадение длин слов
  if (s.length() != t.length()) {
    ans = false;
    std::cout << ans;
    return 0;
  }

  // вносим все символы из первого слова s в словарь и подсчитываем количество
  // каждого
  for (char const& el : s) {
    if (char_list.count(el) == 0)
      char_list[el] = 1;
    else
      char_list[el]++;
  }

  // посимвольно будем проверять совпадение второго слова t с первым s
  for (char const& el : t) {
    // если второе слово t содержит уникальные для первого слова s букву, то
    // возвращаем false
    if (char_list.count(el) == 0) {
      ans = false;
      break;
    }
    // вычитаем соответствующие символы, чтобы проверить совпадение количества
    // соответствующих
    char_list[el]--;
    if (char_list[el] < 0) {
      ans = false;
      break;
    }
  }

  std::cout << ans << "\n";
  return 0;
}