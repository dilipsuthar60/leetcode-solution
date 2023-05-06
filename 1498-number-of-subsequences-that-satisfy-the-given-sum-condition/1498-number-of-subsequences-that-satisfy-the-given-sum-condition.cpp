class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int mod=1e9+7;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(2*dp[i-1])%mod;
        }
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                ans+=dp[r-l];
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans%mod;
    }
};