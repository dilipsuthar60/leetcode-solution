class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mod=1e9+7;
        vector<long long>power(n,1);
        for(int i=1;i<n;i++)
        {
            power[i]=(power[i-1]*2)%mod;
        }
        long long cost=0;
        for(int i=0,j=n-1;i<n;i++,j--)
        {
            cost+=1ll*nums[i]*(power[i]-power[j]);
            cost%=mod;
        }
        return cost;
    }
};