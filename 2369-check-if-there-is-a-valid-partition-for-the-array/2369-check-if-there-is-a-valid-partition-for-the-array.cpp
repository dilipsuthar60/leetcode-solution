class Solution {
public:
    int n;
    int dp[100005];
    bool find(vector<int>&nums,int index)
    {
        if(index>=n)
        {
            return true;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        if(index+1<n&&nums[index]==nums[index+1])
        {
            if(find(nums,index+2))
            {
                return dp[index]=true;
            }
        }
        if(index+2<n&&nums[index]==nums[index+1]&&nums[index+2]==nums[index+1])
        {
            if(find(nums,index+3))
            {
                return dp[index]=true;
            }
        }
        if(index+2<n&&nums[index+1]-nums[index]==1&&nums[index+2]-nums[index+1]==1)
        {
            if(find(nums,index+3))
            return dp[index]=true;
        }
        return dp[index]=false;
    }
    bool validPartition(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return find(nums,0);
    }
};