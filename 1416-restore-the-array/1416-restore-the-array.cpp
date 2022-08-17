class Solution {
public:
    int mod=1e9+7;
    long long dp[100005];
    int find(string &s,int n,int index,int &k)
    {
        if(index==n)
        {
            return 1;
        }
        if(s[index]=='0')
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index]%mod;
        }
        long long ans=0;
        long long sum=0;
        for(int i=index;i<n;i++)
        {
            sum=sum*10+(s[i]-'0');
            if(sum<=k)
            {
                ans+=find(s,n,i+1,k);
            }
            else
            {
                break;
            }
        }
        return dp[index]=ans%mod;
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find(s,s.size(),0,k)%mod;
    }
};