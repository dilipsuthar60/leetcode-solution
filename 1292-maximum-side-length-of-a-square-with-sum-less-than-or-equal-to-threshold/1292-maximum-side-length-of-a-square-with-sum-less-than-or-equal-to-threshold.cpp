class Solution 
{
public:
    int find(vector<vector<int>>&dp,int k,int val)
    {
        for(int i=k;i<dp.size();i++)
        {
            for(int j=k;j<dp[0].size();j++)
            {
                int x=dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k];
                if(val>=x)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat,int val) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=mat[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        int len=0;
        int l=1;
        int r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(dp,mid,val))
            {
                len=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return len;
    }
};
