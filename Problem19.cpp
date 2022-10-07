class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = head, *r = head;
        ++n;
        while(r && n > 0) {
            r = r->next;
            --n;
        }
        if(n > 0) {
            return head->next;
        }
        while(r) {
            l = l->next;
            r = r->next;
        }
        l->next = l->next->next;
        return head;
    }
};

