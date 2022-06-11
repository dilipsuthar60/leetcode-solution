class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        j=0
        sum=0
        count=0
        for i in range(0,len(nums)):
            sum+=nums[i]
            while sum*(i-j+1)>=k:
                sum-=nums[j]
                j+=1
            count+=(i-j+1)
        return count    
        
        