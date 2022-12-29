class Solution {
public:
    long long dp[100005][3];
    int mod=1e9+7;
    long long find(string &s,int index,int k)
    {
        if(index>=s.size())
        {
            return k==2;
        }
        long long ans=0;
        if(dp[index][k]!=-1)
        {
            return dp[index][k]%mod;
        }
        if(k==2)
        {
            if(s[index]=='P')
            {
                ans+=find(s,index+1,k)+find(s,index+1,0);
            }
            else
            {
                ans+=find(s,index+1,1);
            }
        }
        else
        {
            
            if(s[index]=='S')
            {
                k++;
            }
            ans+=find(s,index+1,k);
        }
        return dp[index][k]= ans%mod;
    }
    int numberOfWays(string s) {
        memset(dp,-1,sizeof(dp));
        return (int )find(s,0,0)%mod;
    }
};