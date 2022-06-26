class Solution {
public:
    int dp[200];
    int find(vector<int>&nums,int bound,int index)
    {
        if(index>=bound)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int include=nums[index]+find(nums,bound,index+2);
        int exclude=0+find(nums,bound,index+1);
        return dp[index]=max(include,exclude);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        memset(dp,-1,sizeof(dp));
        int first=find(nums,n-1,0);
        memset(dp,-1,sizeof(dp));
        int second=find(nums,n,1);
        return max(first,second);
    }
};