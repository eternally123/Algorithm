#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) {
      return s;
    }
    int len = 1, start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        bool res = judge(s, i, j);
        if (res) {
          int tmp = j - i + 1;
          if (len < tmp) {
            len = tmp;
            start = i;
            end = j;
          }
        }
      }
    }
    cout << start << "  " << end << endl;
    return s.substr(start, len);
  }
  bool judge(string& s, int begin, int end) {
    //[i,j]
    while (!(begin > end)) {
      if (s[begin] != s[end]) {
        return false;
      }
      begin++;
      end--;
    }
    return true;
  }
};

int main() {
  Solution s;
  string input("cbbd");
  cout << input.size() << endl;
  string res = s.longestPalindrome(input);
  cout << res << endl;
  string tmp("cbbd");
  cout << tmp.substr(0, 2) << endl;
}