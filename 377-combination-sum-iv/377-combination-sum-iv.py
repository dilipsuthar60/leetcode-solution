class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        n=len(nums)
        dp=[0]*(target+1)
        dp[0]=1
        nums.sort()
        for i in range(1,target+1):
            for j in nums:
                if i-j>=0:
                    dp[i]+=dp[i-j]
                else:
                    break
        return dp[target]            
        