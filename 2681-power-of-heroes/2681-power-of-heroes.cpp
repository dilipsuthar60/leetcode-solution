class Solution {
public:
    int mod=1e9+7;
    long long power(long long a,long long b)
    {
        long long res=1;
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
    int sumOfPower(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        long long cost=0;
        long long prev=0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            cost+=power(1ll*nums[i],3);
            cost+=power(1ll*nums[i],2)*prev;
            cost%=mod;
            prev=(prev*2+nums[i])%mod;
        }
        return cost;
    }
};