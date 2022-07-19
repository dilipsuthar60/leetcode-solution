class Solution {
public:
    int dp[510][310];
    int find(vector<int>&nums,int index,int bound,int k)
    {
        if(index>=bound||k==0)
        {
            return 0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int inc=nums[index]+find(nums,index+2,bound,k-1);
        int exc=find(nums,index+1,bound,k);
        return dp[index][k]=max(inc,exc);
    }
    int maxSizeSlices(vector<int>&nums) 
    {
        int n=nums.size();
        int k=n/3;
        memset(dp,-1,sizeof(dp));
        int val1=find(nums,0,n-1,k);
        memset(dp,-1,sizeof(dp));
        int val2=find(nums,1,n,k);
        return max(val1,val2);
    }
};