#include <set>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      unordered_set<char> t;
      int len = 0;
      for (int j = i; j < s.size(); j++) {
        if (t.count(s[j]) == 0) {
          t.insert(s[j]);
          len++;
        } else {
          break;
        }
      }
      res = len > res ? len : res;
    }
    return res;
  }
};