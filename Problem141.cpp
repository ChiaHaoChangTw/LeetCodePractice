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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *walk = head;
        ListNode *run = head->next;
        while (run != walk) {
            if (!run || !run->next) {
                return false;
            }
            walk = walk->next;
            run = run->next->next;
        }
        return true;
    }
};

// Floyd's algorithm
// time: O(n)
// space: O(1)

