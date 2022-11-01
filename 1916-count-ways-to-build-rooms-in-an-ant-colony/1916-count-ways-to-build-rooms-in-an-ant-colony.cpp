class Solution {
public:
    using ll=long long ;
    int mod=1e9+7;
    vector<int>dp[100005];
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
            b=b/2;
        }
        return res;
    }
    void find(int node,vector<ll>&sub,int p=-1)
    {
        for(auto &it:dp[node])
        {
            if(it!=p)
            {
                find(it,sub,node);
                sub[node]+=sub[it];
            }
        }
    }
    int waysToBuildRooms(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                dp[nums[i]].push_back(i);
            }
        }
        vector<ll>sub(n,1);
        find(0,sub);
        ll fact=1;
        for(int i=2;i<=n;i++)
        {
            fact=(fact*i)%mod;
        }
        ll size=1;
        for(int i=0;i<sub.size();i++)
        {
            size=(size*sub[i])%mod;
        }
        ll curr=power(size,mod-2);
        curr=(curr*fact)%mod;
        return curr;
    }
};