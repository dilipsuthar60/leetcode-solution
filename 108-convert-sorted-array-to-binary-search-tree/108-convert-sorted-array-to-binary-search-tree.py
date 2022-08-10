class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def find(l,r):
            if l>r:
                return None
            mid=(l+r)//2
            root=TreeNode(nums[mid])
            root.left=find(l,mid-1)
            root.right=find(mid+1,r)
            return root
        return find(0,len(nums)-1)
        