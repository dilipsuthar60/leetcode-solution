class Solution {
public:
    bool find(vector<int>&nums,long long mid,long long k)
    {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(1ll*nums[i]/mid);
        }
        return sum>=k;
    }
    int maximumCandies(vector<int>& nums, long long k) 
    {
        long long l=1;
        int ans=0;
        long long r=accumulate(nums.begin(),nums.end(),0ll);
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(find(nums,mid,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};