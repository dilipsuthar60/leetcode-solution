class Solution {
public:
    int dp[1100][1100];
    int n;
    string longestPalindrome(string s)     
    {
         n=s.size();
        int len=0;
        memset(dp,0,sizeof(dp));
        for(int d=0;d<n;d++)
        {
            for(int i=0,j=d;j<n;j++,i++)
            {
                if(d==0)
                {
                    dp[i][j]=1;
                }
                else if(d==1)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j])
                {
                    len=d+1;
                }
            }
        }
        // cout<<len<<endl;
        for(int i=0;i+len<=n;i++)
        {
            if(dp[i][i+len-1])
            {
                return s.substr(i,len);
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return "";
    }
};