#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v = sort(nums1, nums2);
    double res = getMid(v);
    return res;
  }
  vector<int> sort(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    v.reserve(nums1.size() + nums2.size());
    v.resize(nums1.size() + nums2.size());
    int i = 0, j = 0;
    int index = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        v[index] = nums1[i];
        i++;
      } else {
        v[index] = nums2[j];
        j++;
      }
      index++;
    }
    while (i < nums1.size()) {
      v[index] = nums1[i];
      i++;
      index++;
    }
    while (j < nums2.size()) {
      v[index] = nums2[j];
      j++;
      index++;
    }
    return v;
  }

  double getMid(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() % 2 == 0) {
      return (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
    }
    if (nums.size() % 2 == 1) {
      return nums[nums.size() / 2];
    }
    return 0.0;
  }
};

int main() {
  Solution s;
  vector<int> v1;
  vector<int> v2;
  v2.push_back(2);
  v2.push_back(3);
  double res = s.findMedianSortedArrays(v1, v2);
}