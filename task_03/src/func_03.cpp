#include "func_03.h"

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int pos, const string& digits,
         const unordered_map<char, string>& phone, string& current,
         vector<string>& result) {
  if (pos == digits.size()) {
    result.push_back(current);
    return;
  }

  for (char c : phone.at(digits[pos])) {
    current.push_back(c);
    dfs(pos + 1, digits, phone, current, result);
    current.pop_back();
  }
}

// digits-цифры current-текущий
// current- текущая строка, которуб мы формируем
vector<string> func(string& digits) {
  unordered_map<char, string> phone = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  vector<string> result;
  string current;

  dfs(0, digits, phone, current, result);

  return result;
}
