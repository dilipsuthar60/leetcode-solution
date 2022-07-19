class Solution {
public:
    int find(vector<int>&nums,int index,int bound,int k,int dp[][310])
    {
        if(index>=bound||k==0)
        {
            return 0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int inc=nums[index]+find(nums,index+2,bound,k-1,dp);
        int exc=find(nums,index+1,bound,k,dp);
        return dp[index][k]=max(inc,exc);
    }
    int maxSizeSlices(vector<int>&nums) 
    {
        int dp[510][310];
        int n=nums.size();
        int k=n/3;
        memset(dp,-1,sizeof(dp));
        int val1=find(nums,0,n-1,k,dp);
        memset(dp,-1,sizeof(dp));
        int val2=find(nums,1,n,k,dp);
        return max(val1,val2);
    }
};