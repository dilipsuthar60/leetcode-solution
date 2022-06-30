class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums=sorted(nums)
        count=0
        mid=nums[len(nums)//2]
        for i in nums:
            count+=abs(i-mid)
        return count    
            
        