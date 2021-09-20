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

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    
    ListNode* deleteDuplicates(ListNode* cur) {
        ListNode *result = nullptr;
        while (cur) {
            int val = cur->val;
            if (cur->next != nullptr && cur->next->val == val) {
                while (cur->next != nullptr && cur->next->val == val) {
                    cur = cur->next;
                }
            } else {
                ListNode* node = new ListNode(val);
                node->next = result;
                result = node;
            }
            cur = cur->next;
        }
        return reverse(result);
    }
};