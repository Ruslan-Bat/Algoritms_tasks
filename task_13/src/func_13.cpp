#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<pair<double, double>> func(int n,
                                  vector<pair<double, double>>& lessons) {
  sort(lessons.begin(), lessons.end(),
       [](const pair<double, double>& a, const pair<double, double>& b) {
         if (a.second != b.second) {
           return a.second < b.second;
         }
         return a.first < b.first;
       });

  vector<pair<double, double>> selected;
  double last_end_time = -1.0;

  for (const auto& lesson : lessons) {
    if (lesson.first >= last_end_time) {
      selected.push_back(lesson);
      last_end_time = lesson.second;
    }
  }
  return selected;
}