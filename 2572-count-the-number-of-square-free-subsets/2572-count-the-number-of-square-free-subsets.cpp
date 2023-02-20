class Solution {
public:
    int mod=1e9+7;
    vector<int>prime;
    int mp[45];
    long long dp[31][1<<12];
    int find(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    long long find(int value,int mask)
    {
        if(value>30)
        {
            return (mask>0);
        }
        if(dp[value][mask]!=-1)
        {
            return dp[value][mask]%mod;
        }
        int new_mask=0;
        long long product=1;
        for(int i=0;i<prime.size();i++)
        {
            if((value%prime[i])==0)
            {
                product*=prime[i];
                new_mask|=(1<<i);
            }
        }
        long long ans=find(value+1,mask);
        if(product==value&&mp[value]&&((mask&new_mask)==0))
        {
            ans+=(find(value+1,mask|new_mask)*mp[value]);
        }
        return dp[value][mask]=ans%mod;
    }
    int squareFreeSubsets(vector<int>& nums) 
    {
        long long count=0;
        for(auto it:nums)
        {
            if(it==1)
            {
                count++;
            }
        }
        memset(dp,-1,sizeof(dp));
        for(int i=2;i<=30;i++)
        {
            if(find(i))
            {
                prime.push_back(i);
            }
        }
        for(auto it:nums)
        {
            mp[it]++;
        }
        long long val=find(2,0)%mod;
        long one=1;
        for(int i=0;i<mp[1];i++)
        {
            one=(one*2)%mod;
        }
        val=(val*one)%mod;
        if(count)
        {
            long long r=1;
            for(int i=0;i<count;i++)
            {
                r*=2;
                r%=mod;
            }
            count=r-1;
        }
        return (val+count)%mod;
    }
};