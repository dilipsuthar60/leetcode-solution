class Solution {
public:
    int videoStitching(vector<vector<int>>& nums, int time) 
    {
        vector<int>dp(101,0);
        for(int i=0;i<nums.size();i++)
        {
            dp[nums[i][0]]=max(dp[nums[i][0]],nums[i][1]);
        }
        int jump=dp[0];
        int count=1;
        int max_jump=jump;
        for(int i=1;i<=time;i++)
        {
            if(jump>=time)
            {
                break;
            }
            if(i>max_jump)
            {
                return -1;
            }
            max_jump=max(max_jump,dp[i]);
            if(i==jump)
            {
                jump=max_jump;
                count++;
            }
        }
        return count;
    }
};