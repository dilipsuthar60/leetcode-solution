class Solution {
public:
    int n;
    int dp[201][201];
    int find(vector<vector<int>>&nums,int i,int j)
    {
        if(i==n-1)
        {
            return nums[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=nums[i][j]+min(find(nums,i+1,j),find(nums,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return find(nums,0,0);
    }
};