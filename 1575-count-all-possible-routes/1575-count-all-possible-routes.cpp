class Solution {
public:
    long long  dp[110][300];
    int n;
    const int mod=1e9+7;
    long long find(vector<int>&nums,int start,int finish,int fuel)
    {
        if(fuel<0)
        {
            return 0;
        }
        if(dp[start][fuel]!=-1)
        {
            return dp[start][fuel]%mod;
        }
        long long ans=0;
        if(start==finish)
        {
            ans++;
        }
        for(int i=0;i<n;i++)
        {
            if(start!=i&&abs(nums[i]-nums[start])<=fuel)
            {
                ans+=find(nums,i,finish,fuel-abs(nums[i]-nums[start]));
            }
        }
        return dp[start][fuel]=ans%mod;
    }
    int countRoutes(vector<int>&nums, int start, int finish, int fuel) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return (int)find(nums,start,finish,fuel)%mod;
    }
};