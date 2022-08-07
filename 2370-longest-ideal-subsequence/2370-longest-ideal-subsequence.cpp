class Solution {
public:
    int longestIdealString(string s, int k) 
    {
        int n=s.size();
        int dp[26];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(auto &it:s)
        {
            int i=it-'a';
            dp[i]=dp[i]+1;
            for(int j=max(0,i-k);j<=min(25,i+k);j++)
            {
                if(i!=j)
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};