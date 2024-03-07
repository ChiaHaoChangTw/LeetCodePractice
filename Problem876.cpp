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
    ListNode* middleNode(ListNode* head) {
        ListNode *walk = head;
        ListNode *run = head->next;
        while (run && run->next) {
            walk = walk->next;
            run = run->next->next;
        }
        return run ? walk->next : walk;
    }
};

// two pointers
// time: O(n)
// space: O(1)

