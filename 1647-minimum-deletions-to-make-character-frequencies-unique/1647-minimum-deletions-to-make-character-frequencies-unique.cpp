class Solution {
public:
    int minDeletions(string s) 
    {
        int n=s.size();
        int dp[26]={0};
        for(int i=0;i<n;i++)
        {
            dp[s[i]-'a']++;
        }
        int del=0;
        int max_freq=s.size();
        sort(dp,dp+26);
        for(int i=25;i>=0&&dp[i]>0;i--)
        {
            if(dp[i]>max_freq)
            {
                del+=dp[i]-max_freq;
                dp[i]=max_freq;
            }
            max_freq=max(0,dp[i]-1);
        }
        return del;
    }
};