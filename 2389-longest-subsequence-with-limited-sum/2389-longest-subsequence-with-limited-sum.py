class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        def bs(a,val):
            l,r=0,len(a)-1
            while l<=r:
                mid=(l+r)//2
                if a[mid]<=val:
                    l=mid+1
                else:
                    r=mid-1
            return l
            
        nums.sort()
        for i in range(1,len(nums)):
            nums[i]+=nums[i-1]
        ans=[]
        for i in queries:
            ans.append(bs(nums,i))
        return ans
        
        