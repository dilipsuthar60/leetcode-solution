class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        int dp[value+1];
        memset(dp,0,sizeof(dp));
        for(auto it:nums)
        {
            dp[(it%value+value)%value]++;
        }
        int ans=0;
        while(dp[ans%value])
        {
            dp[ans%value]--;
            ans++;
        }
        return ans;
    }
};