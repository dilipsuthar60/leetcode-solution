class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) 
    {
        int n=nums.size();
        long long l=1;
        int ans=0;
        long long r=*max_element(nums.begin(),nums.end());
        auto find=[&](long long mid)
      {
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(1ll*nums[i]/mid);
        }
        return sum>=k;
    };
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(find(mid))
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