#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    string res;
    int step = (numRows - 2) * 2 + 2;
    for (int i = 0; i < numRows; i++) {
      if (i == 0 || i == numRows - 1) {
        string tmp = read(s, i, step);
        // cout << "s= " << tmp << endl;
        res += tmp;
      } else {
        string s1 = read(s, i, step);
        // cout << "s1= " << s1 << endl;
        string s2 = read(s, step - i, step);
        // cout << "s2= " << s2 << endl;
        string tmp = join(s1, s2);
        // cout << "s= " << tmp << endl;
        res += tmp;
      }
    }
    return res;
  }

  string read(string& s, int begin, int step) {
    string res;
    int index = begin;
    while (index < s.size()) {
      res.append(s.substr(index, 1));
      index += step;
    }
    return res;
  }
  string join(string& s1, string& s2) {
    string res;
    int i = 0, j = 0;
    while (i < s1.size() || j < s2.size()) {
      if (i < s1.size()) {
        res.append(s1.substr(i, 1));
      }
      if (j < s2.size()) {
        res.append(s2.substr(j, 1));
      }
      i++;
      j++;
    }
    return res;
  }
};

int main() {
  Solution s;
  s.convert("PAYPALISHIRING", 3);
}