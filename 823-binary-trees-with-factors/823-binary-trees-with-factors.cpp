
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>&nums) 
    {
        int mod=1e9+7;
        int n=nums.size();
        unordered_map<int,long long>dp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            dp[nums[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                dp[nums[i]]=(dp[nums[i]]+dp[nums[j]]*dp[nums[i]/nums[j]])%mod;
            }
            // cout<<dp[nums[i]]<<" ";
        }
        int sum=0;
        for(auto &[a,b]:dp)
        {
            sum=(sum+b)%mod;
        }
        return sum;
    }
};