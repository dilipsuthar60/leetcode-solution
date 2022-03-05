class Solution {
public:
    int max_range=0;
    int deleteAndEarn(vector<int>& nums) 
    {
        int n=nums.size();
        max_range=*max_element(nums.begin(),nums.end());
        vector<int>array(max_range+1,0);
        for(int i=0;i<n;i++)
        {
            array[nums[i]]++;
        }
        for(int i=0;i<max_range+1;i++)
        {
            array[i]=array[i]*i;
        }
        vector<int>dp(max_range+10,0);
        dp[0]=array[0];
        dp[1]=array[1];
        for(int i=2;i<=max_range;i++)
        {
            dp[i]=max(array[i]+dp[i-2],dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};