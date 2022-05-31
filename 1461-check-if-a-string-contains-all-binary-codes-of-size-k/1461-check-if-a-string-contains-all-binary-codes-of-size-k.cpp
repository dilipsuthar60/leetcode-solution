class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        
        int size=1<<k;
        int dp[size+1];
        memset(dp,-1,sizeof(dp));
        int allone=size-1;
        int hash=0;
        int count=0;
        for(int i=0,n=s.size();i<n;i++)
        {
            hash=((hash<<1)&(allone))|(s[i]-'0');
            if(i>=k-1&&dp[hash]==-1)
            {
                dp[hash]=1;
                count++;
            }
        }
        return count==size;
    }
};