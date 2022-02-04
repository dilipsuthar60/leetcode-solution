class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>p(n,0);
        p[0]=1;
        int mod=1e9+7;
        for(int i=1;i<n;i++)
        {
            p[i]=(2*p[i-1])%mod;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=1ll*nums[i]*(p[i]-p[n-i-1]);
            ans%=mod;
        }
        return (int)ans;
    }
};