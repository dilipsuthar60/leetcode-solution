class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>&nums, int st) 
    {
        int n=nums.size();
        int dp[st+2];
        memset(dp,0,sizeof(dp));
        for(auto it:nums)
        {
            dp[it[0]]+=it[2];
            dp[it[1]+1]-=it[2];
        }
        for(int i=1;i<=st;i++)
        {
           dp[i]+=dp[i-1];
        }
        vector<int>ans;
        for(int i=1;i<=st;i++)
        {
            ans.push_back(dp[i]);
        }
        return ans;
    }
};