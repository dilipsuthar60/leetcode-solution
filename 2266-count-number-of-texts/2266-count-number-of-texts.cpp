class Solution {
public:
    int n;
    int mod=1e9+7;
    long long dp[100006];
    // int find(string &s,int index)
    // {
    //     if(index>=n)
    //     {
    //         return 1;
    //     }
    //     if(dp[index]!=-1)
    //     {
    //         return dp[index]%mod;
    //     }
    //     long long ans=find(s,index+1);
    //     if(index+1<n&&s[index]==s[index+1])
    //     {
    //         ans+=find(s,index+2);
    //     }
    //     if(index+2<n&&s[index]==s[index+1]&&s[index]==s[index+2])
    //     {
    //         ans+=find(s,index+3);
    //     }
    //     if(index+3<n&&(s[index]=='7'||s[index]=='9')&&s[index]==s[index+1]&&s[index]==s[index+2]&&s[index]==s[index+3])
    //     {
    //         ans+=find(s,index+4);
    //     }
    //     return dp[index]=ans%mod;
    // }
    int countTexts(string s) {
        n=s.size();
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(i-2>=0&&s[i-1]==s[i-2])
            {
                dp[i]+=dp[i-2];
            }
            if(i-3>=0&&s[i-1]==s[i-2]&&s[i-1]==s[i-3])
            {
                dp[i]+=dp[i-3];
            }
            if(i-4>=0&&(s[i-1]=='7'||s[i-1]=='9')&&s[i-1]==s[i-2]&&s[i-1]==s[i-3]&&s[i-1]==s[i-4])
            {
                dp[i]+=dp[i-4];
            }
            dp[i]%=mod;
        }
        return dp[n]%mod;
    }
};