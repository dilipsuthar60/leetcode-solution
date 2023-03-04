class Solution {
public:
    using ll=long long;
    long long dp[100005][3];
    int mod=1e9+7;
    vector<vector<int>> merge(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        if(n==0)
        {
            return {};
        }
        int j=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[j][1]>=nums[i][0])
            {
                nums[j][1]=max({nums[j][1],nums[i][1]});
            }
            else
            {
                nums[++j]=nums[i];
            }
        }
        return vector<vector<int>>(nums.begin(),nums.begin()+j+1);
    }
    ll power(ll a,ll b)
{ll res=1;while(b){if(b&1){res=(res*a)%mod;}a=(a*a)%mod; b>>=1; }return res;}    
    int countWays(vector<vector<int>>& nums) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>v=merge(nums);  
        return power(2,v.size());
    }
};