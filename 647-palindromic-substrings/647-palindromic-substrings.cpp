class Solution {
public:
    int countSubstrings(string s) 
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
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
                    dp[i][j]=(s[i]==s[j])?1:0;
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
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                count+=dp[i][j];
            }
        }
        return count;
    }
};