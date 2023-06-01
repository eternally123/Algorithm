#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    string s = to_string(x);
    string s1 = "";
    string s2 = "";
    if (s[0] == '-') {
      s1.push_back(s[0]);
      s2 = myreverse(s.substr(1, s.size() - 1));
    } else {
      s2 = myreverse(s.substr(0, s.size()));
    }
    string reverseS = s1 + s2;
    if (isValid(s1, s2)) {
      return atoi(reverseS.c_str());
    } else {
      return 0;
    }
  }

 private:
  bool isValid(string s1, string s2) {
    if (s1.size() == 0) {
      return compareStr(s2, to_string(INT32_MAX));
    } else {
      string tmp = to_string(INT32_MIN);
      return compareStr(s2, tmp.substr(1, tmp.size() - 1));
    }
  }

  // s1 < s2
  bool compareStr(string s1, string s2) {
    if (s1.size() < s2.size()) {
      return true;
    } else if (s1.size() > s2.size()) {
      return false;
    } else {
      for (int i = 0; i < s1.size(); i++) {
        if (s1[i] < s2[i]) {
          return true;
        } else if (s1[i] > s2[i]) {
          return false;
        } else {
          continue;
        }
      }
      return true;
    }
  }

  string myreverse(string s) {
    if (s.size() <= 1) {
      return s;
    }
    string res = "";
    bool zero = true;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (zero) {
        if (s[i] == '0') {
          continue;
        } else {
          zero = false;
        }
      }
      res.push_back(s[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  int res = s.reverse(-123);
  cout << res << endl;
}