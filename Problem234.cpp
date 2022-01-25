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
        if(!head->next){return true;}
        ListNode* tail = findMid(head);
        ListNode* midHead = tail->next;
        tail->next = nullptr;
        ListNode* revMidHead = reverseList(midHead);
        bool result = compare2Lists(head, revMidHead);
        midHead = reverseList(revMidHead);
        tail->next = midHead;
        return result;
    }
private:
    ListNode* findMid(ListNode* head){
        ListNode *pre = head, *walk = head->next, *run = head->next->next;
        while(run && run->next){
            pre = pre->next, walk = walk->next, run = run->next->next;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* head){
        ListNode *pre = nullptr, *curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr, curr = temp;
        }
        return pre;
    }
    bool compare2Lists(ListNode* head1, ListNode* head2){
        while(head1 && head2){
            if(head1->val != head2->val){return false;}
            head1 = head1->next, head2 = head2->next;
        }
        return true;
    }
};
