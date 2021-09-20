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

// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    
    ListNode* reverse(ListNode* l) {
        ListNode *node = nullptr;
        while (l != nullptr) {
            ListNode *cur = new ListNode(l->val);
            cur->next = node;
            node = cur;
            l = l->next;
        } 
        return node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        int remainder = 0;
        while (l1 != nullptr || l2 != nullptr) {
            ListNode *node = new ListNode();
            if (l1 != nullptr) {
                node->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                node->val += l2->val;
                l2 = l2->next;
            }
            node->val += remainder;
            if (node->val >= 10) {
                node->val -= 10;
                remainder = 1;
            } else {
                remainder = 0;
            }
            node->next = result;
            result = node;
        }
        if (remainder == 1) {
            ListNode *node = new ListNode(1);
            node->next = result;
            result = node;
        }
        return reverse(result);
    }
};