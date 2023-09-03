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

#include "common.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 双指指法
        ListNode *cur = nullptr, *next = head;
        while(next != nullptr) {
            auto * nextnext = next->next; // 这里临时记录一下下一步的位置
            next->next = cur; // 完成反转
            // 双指针移动
            cur = next;
            next = nextnext;
        }
        return cur;
    }

};