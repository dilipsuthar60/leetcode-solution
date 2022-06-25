class Solution {
public:
    int dp[60][6];
    int find(int n,int index,int prev)
    {
        if(index==n)
        {
            return 1;
        }
        if(dp[index][prev]!=-1)
        {
            return dp[index][prev];
        }
        int ans=0;
        for(int i=1;i<=5;i++)
        {
            if(prev<=i)
            {
                ans+=find(n,index+1,i);
            }
        }
        return dp[index][prev]=ans;
    }
    int countVowelStrings(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return find(n,0,0);
    }
};