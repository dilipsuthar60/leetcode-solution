class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,'a');
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(lcp[i][j]==0&&ans[i]==ans[j])
                {
                    ans[j]++;
                    if(ans[j]>'z')
                    {
                        return "";
                    }
                }
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(ans[i]==ans[j])
                {
                    dp[i][j]=dp[i+1][j+1]+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]!=lcp[i][j])
                {
                    return "";
                }
            }
        }
        return ans;
    }
};