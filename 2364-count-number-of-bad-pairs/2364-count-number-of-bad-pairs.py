class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        mp=dict()
        n=len(nums)
        count=n*(n-1)//2
        for i in range(0,n):
            if nums[i]-i in mp:
                count-=mp[nums[i]-i]
            if nums[i]-i not in mp:
                mp[nums[i]-i]=0
            mp[nums[i]-i]+=1    
        return count    
        