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
    bool isPalindrome(ListNode* head) {
        ListNode *mid = findMid(head);
        ListNode *revHead = reverseList(mid->next);
        ListNode *l = head;
        ListNode *r = revHead;
        bool isPal = true;
        while (isPal && r) {
            if (l->val != r->val) {
                isPal = false;
            }
            l = l->next;
            r = r->next;
        }
        return isPal;
    }

private:
    ListNode *reverseList(ListNode* head) {
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

    ListNode *findMid(ListNode* head) {
        ListNode *walk = head;
        ListNode *run = head;
        while (run->next && run->next->next) {
            run = run->next->next;
            walk = walk->next;
        }
        return walk;
    }
};

// linked list
// time: O(n)
// space: O(1)

