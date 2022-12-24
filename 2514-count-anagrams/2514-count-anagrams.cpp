class Solution {
public:
    using ll =long long;
    ll mod=1e9+7;
    ll fact[100005];
    ll power(ll a,ll b)
    {
        ll res=1;
        while(b)
        {
            if(b&1)
            {
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        return res;
    }
    ll cal(vector<int>&dp)
    {
        ll sum=0;
        for(int i=0;i<26;i++)
        {
            sum+=dp[i];
        }
        ll ans=fact[sum];
        for(int i=0;i<26;i++)
        {
            ans*=(power(fact[dp[i]],mod-2));
            ans%=mod;
        }
        return ans;
    }
    int countAnagrams(string s) 
    {
        fact[0]=1;
        for(int i=1;i<100005;i++)
        {
            fact[i]=(i*fact[i-1])%mod;
        }
        int n=s.size();
        vector<int>dp(26,0);
        ll ans=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                ll value=cal(dp);
                ans*=value;
                ans%=mod;
                dp=vector<int>(26,0);
            }
            else
            {
                dp[s[i]-'a']++;
            }
        }
        ll value=cal(dp);
        ans*=value;
        ans%=mod;
        return (int)ans;
    }
};