class Solution {
public:
    int findTheCity(int n, vector<vector<int>>&mat, int val) 
    {
        vector<vector<int>>dp(n,vector<int>(n,1e5));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(auto &it:mat)
        {
            dp[it[0]][it[1]]=it[2];
            dp[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans=0;
        int max_val=n;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]<=val)
                {
                    count++;
                }
            }
            if(count<=max_val)
            {
                max_val=count;
                ans=i;
            }
        }
        return ans;
    }
};
