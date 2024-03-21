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

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode *newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return newHead;
//     }
// };

// recursive
// time: O(n)
// space: O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = nullptr;
        ListNode *currNode = head;
        ListNode *nextNode = head ? head->next : head;
        while (currNode) {
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode ? nextNode->next : nextNode;
        }
        return prevNode;
    }
};

// iterative
// time: O(n)
// space: O(1)

