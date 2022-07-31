class Solution:
    def maximumGroups(self, grades: List[int]) -> int:
        l,r=0,10**9;
        ans=-1
        while l<=r:
            mid=(l+r)//2
            if mid*(mid+1)/2<=len(grades):
                ans=mid
                l=mid+1
            else:
                r=mid-1
        return ans        
        
        