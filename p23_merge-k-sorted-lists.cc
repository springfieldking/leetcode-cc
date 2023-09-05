/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <queue>
#include <vector>
#include "common.h"

using namespace std;
class Solution {
  struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
      return a->val > b->val;  // 按照value从小到大排列
    }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for (ListNode* node : lists) {
      if (node) q.push(node);
    }

    ListNode head, *tail = &head;
    while (!q.empty()) {
      ListNode* n = q.top();
      q.pop();

      tail->next = n;
      tail = tail->next;
      if (n->next) q.push(n->next);
    }
    return head.next;
  }
};

int main() { Solution s; }