class Solution {
public:
    bool find(vector<vector<int>>&mat,int mid)
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[1][1]=mid+mat[0][0];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]>0?dp[i-1][j]+mat[i-1][j-1]:0);
                dp[i][j]=max(dp[i][j],dp[i][j-1]>0?dp[i][j-1]+mat[i-1][j-1]:0);
            }
        }
        return dp[n][m]>0;
    }
    int calculateMinimumHP(vector<vector<int>>&nums) 
    {
        int n=nums.size();
        int m=nums[0].size();
        int l=0;
        int r=1e9;
        int ans=INT_MAX;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(find(nums,mid))
            {
                ans=mid;
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        return ans;
    }
};