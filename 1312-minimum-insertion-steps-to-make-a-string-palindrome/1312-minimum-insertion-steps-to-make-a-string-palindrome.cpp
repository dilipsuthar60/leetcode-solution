class Solution {
public:
    int minInsertions(string s) 
    {
        int n=s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i+1][j+1]=(s[i]==s[n-j-1])?1+dp[i][j]:max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return n-dp[n][n];
    }
};