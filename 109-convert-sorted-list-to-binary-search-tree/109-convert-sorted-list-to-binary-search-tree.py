# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def covert(head):
            nums=[]
            while head:
                nums.append(head.val)
                head=head.next
            return nums    
        def find(l,r):
            if l>r:
                return None
            mid=(l+r)//2
            root=TreeNode(nums[mid])
            root.left=find(l,mid-1)
            root.right=find(mid+1,r)
            return root
        nums=covert(head)
        return find(0,len(nums)-1)
        