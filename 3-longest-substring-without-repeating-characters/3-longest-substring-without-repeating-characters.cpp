class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int dp[260];
        memset(dp,-1,sizeof(dp));
        int i,j;
        i=j=0;
        int n=s.size();
        int len=0;
        while(i<n&&j<n)
        {
            if(dp[s[i]]==-1)
            {
                len=max(len,i-j+1);
                dp[s[i++]]=1;
            }
            else
            {
                dp[s[j]]=-1;
                j++;
            }
        }
        return len;
    }
};