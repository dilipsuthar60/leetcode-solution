# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def find(root,left,right):
            if root is None:
                return True
            return root.val>left and root.val<right and find(root.left,left,root.val) and find(root.right,root.val,right)
        return find(root,-10**11,10**11)
        