class Solution {
public:
    int maxProduct(vector<string>&nums) 
    {
        int n=nums.size();
        vector<pair<int,int>>dp(n);
        for(int i=0;i<n;i++)
        {
            int mask=0;
            for(auto it:nums[i])
            {
                mask|=1<<(it-'a');
            }
            dp[i]={mask,nums[i].size()};
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((dp[i].first&dp[j].first)==0)
                {
                    ans=max(ans,dp[i].second*dp[j].second);
                }
            }
        }
        return ans;
    }
};