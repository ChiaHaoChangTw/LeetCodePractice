# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head.next is None:
            return True
        tail = self.findMid(head)
        midHead = tail.next
        tail.next = None
        revMidHead = self.reverseList(midHead)
        result = self.compare2Lists(head, revMidHead)
        midHead = self.reverseList(revMidHead)
        tail.next = midHead
        return result
        
    def findMid(self, head) -> ListNode:
        pre = head
        walk = head.next
        run = head.next.next
        while run is not None and run.next is not None:
            pre = pre.next
            walk = walk.next
            run = run.next.next
        return pre
        
    def reverseList(self, head) -> ListNode:
        pre = None
        curr = head
        while curr is not None:
            temp = curr.next
            curr.next = pre
            pre = curr
            curr = temp
        return pre
        
    def compare2Lists(self, head1, head2) -> bool:
        while head1 is not None and head2 is not None:
            if head1.val != head2.val:
                return False
            head1 = head1.next
            head2 = head2.next
        return True

