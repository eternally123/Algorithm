/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res = new ListNode(0, nullptr);
    ListNode* begin = res;
    int tmp_value = 0;  // 十分位
    int v = 0;          // 个位
    while (l1 != nullptr && l2 != nullptr) {
      v = (l1->val + l2->val + tmp_value) % 10;
      tmp_value = (l1->val + l2->val + tmp_value) / 10;
      ListNode* node = new ListNode(v, nullptr);
      res->next = node;
      res = res->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    ListNode* ptr = (l1 == nullptr) ? l2 : l1;
    while (ptr != nullptr) {
      v = (ptr->val + tmp_value) % 10;
      tmp_value = (ptr->val + tmp_value) / 10;
      ListNode* node = new ListNode(v, nullptr);
      res->next = node;
      res = res->next;
      ptr = ptr->next;
    }
    if (tmp_value != 0) {
      ListNode* node = new ListNode(tmp_value, nullptr);
      res->next = node;
    }
    res = begin->next;
    delete begin;
    return res;
  }
};