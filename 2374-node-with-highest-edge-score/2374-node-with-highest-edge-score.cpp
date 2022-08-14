class Solution {
public:
    int edgeScore(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long>dp(n+1);
        for(long long i=0;i<n;i++)
        {
            dp[nums[i]]+=i;
        }
        long long max_score=0;
        for(int i=0;i<n;i++)
        {
            max_score=max(max_score,dp[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(max_score==dp[i])
            {
                return i;
            }
        }
        return -1;
    }
};