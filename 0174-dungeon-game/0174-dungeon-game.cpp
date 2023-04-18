class Solution {
public:
    int find(vector<vector<int>>&mat,int mid)
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=mat[0][0]+mid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i&&dp[i-1][j])
                {
                    dp[i][j]=max(dp[i][j],mat[i][j]+dp[i-1][j]);
                }
                if(j&&dp[i][j-1])
                {
                    dp[i][j]=max(dp[i][j],mat[i][j]+dp[i][j-1]);
                }
            }
        }
        return (dp[n-1][m-1]>0);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int ans=0;
        int l=1;
        int r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(dungeon,mid))
            {
                r=mid-1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};