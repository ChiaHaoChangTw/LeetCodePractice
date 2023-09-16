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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA;
        ListNode *currB = headB;
        while (currA != currB) {
            if (!currA) {
                currA = headB;
            } else {
                currA = currA->next;
            }
            if (!currB) {
                currB = headA;
            } else {
                currB = currB->next;
            }
        }
        return currA;
    }
};

// 2 pointers

// ***~~*~~
// *~~***~~

// *****
// *****

// time O(m + n)
// space O(1)

