class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyHead = new ListNode();
        ListNode* currNode = dummyHead;
        
        while(l1 || l2) {
            int nodeValue1 = getCurrNodeValue(l1);
            int nodeValue2 = getCurrNodeValue(l2);
            int currSum = nodeValue1 + nodeValue2 + carry;
            carry = currSum / 10;
            currSum %= 10;
            currNode->next = new ListNode(currSum);
            currNode = currNode->next;
        }
        
        if(carry) {
            currNode->next = new ListNode(carry);
        }
        
        return dummyHead->next;
    }
    
private:
    int getCurrNodeValue(ListNode*& currNode) {
        if(!currNode) {
            return 0;
        }
        int currNodeValue = currNode->val;
        currNode = currNode->next;
        return currNodeValue;
    }
};

