class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int value=*max_element(nums.begin(),nums.end());
        int dp[value+1];
        memset(dp,0,sizeof(dp));
        for(auto it:nums)
        {
            dp[it]++;
        }
        for(int i=1;i<=value;i++)
        {
            dp[i]=max(i*dp[i]+((i-2>=0)?dp[i-2]:0),dp[i-1]);
        }
        return *max_element(dp,dp+value+1);
    }
};