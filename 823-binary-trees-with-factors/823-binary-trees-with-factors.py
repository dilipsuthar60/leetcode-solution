class Solution:
    def numFactoredBinaryTrees(self, nums: List[int]) -> int:
        dp={}
        nums.sort()
        # print(nums)
        for i in range(0,len(nums)):
            dp[nums[i]]=1;
            for j in range(i):
                if nums[i]%nums[j]==0:
                    dp[nums[i]]+=(dp.get(nums[j],0)*dp.get(nums[i]/nums[j],0))
            # print(dp[nums[i]])
                    
        ans=0;
        for a,b in dp.items():
            ans=(ans+b)%(10**9+7)
        return ans
            
        