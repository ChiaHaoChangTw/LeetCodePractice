class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        
        for(int step = 1; step < lists.size(); step *= 2) {
            int pos1 = 0, pos2 = step;
            while(pos2 < lists.size()) {
                lists[pos1] = mergeTwoLists(lists[pos1], lists[pos2]);
                pos1 += (step * 2);
                pos2 = pos1 + step;
            }
        }
        
        return lists[0];
    }
    
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) {
            return nullptr;
        } else if(!list1) {
            return list2;
        } else if(!list2) {
            return list1;
        }
        
        ListNode* dummyHead = new ListNode();
        ListNode* currNode = dummyHead;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                currNode->next = list1;
                currNode = currNode->next;
                list1 = list1->next;
            } else {
                currNode->next = list2;
                currNode = currNode->next;
                list2 = list2->next;
            }
        }
        
        if(list1) {
            currNode->next = list1;
        }
        if(list2) {
            currNode->next = list2;
        }
        
        currNode = dummyHead->next;
        delete dummyHead;
        return currNode;
    }
};

