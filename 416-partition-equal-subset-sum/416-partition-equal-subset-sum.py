class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total=sum(nums)
        if total%2==1:
            return False
        total=total//2
        dp=1
        for i in nums:
            dp|=(dp<<i)
        return dp&(1<<total)    
        