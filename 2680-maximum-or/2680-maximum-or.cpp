class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<long long>left(n,0),right(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                left[i]=nums[i];
            }
            else
            left[i]=left[i-1]|nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                right[i]=nums[i];
            }
            else
            {
                right[i]=right[i+1]|nums[i];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long value=(1ll*nums[i]*(1<<k));
            long long current=(i>0?left[i-1]:0)|value|(i+1<n?right[i+1]:0);
            ans=max(ans,current);
        }
        return ans;
    }
};