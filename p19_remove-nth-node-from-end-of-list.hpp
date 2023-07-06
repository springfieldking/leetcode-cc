
#include "common.h"

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 左右指针
        ListNode dummy;
        dummy.next = head;
        ListNode* r = &dummy;
        ListNode* l = &dummy;

        // 右指针先跑n次
        while(n > 0) {
            n--;
            r = r->next;
        }

        // 左右一起跑,知道右指针指向结尾
        while(r->next != nullptr) {
            r = r->next;
            l = l->next;
        }

        // 此时左指针位于倒数n的位置,删除即可
        l->next = l->next->next;
        return dummy.next;
    }
};