class Solution {
public:
    int n;
    int memo[2001];
    int dp[2001][2001];
    int find(string &s,int index)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index][n-1])
        {
            return 0;
        }
        if(memo[index]!=-1)
        {
            return memo[index];
        }
        int ans=1e9;
        for(int i=index;i<n;i++)
        {
            if(dp[index][i])
            {
                ans=min(ans,1+find(s,i+1));
            }
        }
        return memo[index]=ans;
    }
    int minCut(string s) 
    {
        memset(dp,0,sizeof(dp));
        memset(memo,-1,sizeof(memo));
        n=s.size();
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;j++,i++)
            {
                if(gap==0)
                {
                    dp[i][j]=1;
                }
                else if(gap==1)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])
                    {
                        dp[i][j]=1;
                    }
                }
            }
        }
        return find(s,0);
    }
};