class Solution {
public:
    int n;
    int mod=1e9+7;
    long long dp[100006];
    int find(string &s,int index)
    {
        if(index>=n)
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index]%mod;
        }
        long long ans=find(s,index+1);
        if(index+1<n&&s[index]==s[index+1])
        {
            ans+=find(s,index+2);
        }
        if(index+2<n&&s[index]==s[index+1]&&s[index]==s[index+2])
        {
            ans+=find(s,index+3);
        }
        if(index+3<n&&(s[index]=='7'||s[index]=='9')&&s[index]==s[index+1]&&s[index]==s[index+2]&&s[index]==s[index+3])
        {
            ans+=find(s,index+4);
        }
        return dp[index]=ans%mod;
    }
    int countTexts(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return find(s,0)%mod;
    }
};