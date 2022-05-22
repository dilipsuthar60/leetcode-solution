class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        int ans=1;
        sort(nums.begin(),nums.end());
        using ll=long long;
        for(int i=2;i<n;i++)
        {
            ll y1=nums[i-1][1]-nums[i-2][1];
            ll x1=nums[i-1][0]-nums[i-2][0];
            ll y0=nums[i][1]-nums[i-1][1];
            ll x0=nums[i][0]-nums[i-1][0];
            if(y1*x0!=y0*x1)
            {
                ans++;
            }
        }
        return ans;
    }
};