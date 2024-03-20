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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prev = nullptr;
        ListNode *curr = list1;
        int index = 0;
        while (index < a) {
            prev = curr;
            curr = curr->next;
            ++index;
        }
        prev->next = list2;
        ListNode *remove = curr;
        while (index <= b) {
            prev = curr;
            curr = curr->next;
            ++index;
        }
        prev->next = nullptr;
        ListNode *tail = list2;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = curr;
        while (remove) {
            ListNode *temp = remove;
            remove = remove->next;
            delete temp;
        }
        return list1;
    }
};

// linked list
// time: O(m + n)
// space: O(1)

