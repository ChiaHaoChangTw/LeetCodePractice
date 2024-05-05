/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode *nextNode = node->next;
        node->next = nextNode->next;
        delete nextNode;
    }
};

// linked list
// time: O(1)
// space: O(1)

