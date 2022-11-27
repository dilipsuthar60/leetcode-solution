class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        vector<unordered_map<long long,int>>dp(n+1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff=1ll*(nums[i])-1ll*(nums[j]);
                ans+=dp[j][diff];
                dp[i][diff]+=dp[j][diff]+1;
            }
        }
        return ans;
    }
};