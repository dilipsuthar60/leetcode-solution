class Solution {
public:
    bool find(vector<int>&nums,long long val,long long mid)
    {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(mid/nums[i]);
        }
        return sum>=val;
    }
    long long minimumTime(vector<int>&nums, int total) 
    {    
        if(nums.size()==1)
        {
            return 1ll*nums[0]*total;
        }
        long long l=1;
        long long r=1e10;
        int ans=nums.size();
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(find(nums,total,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};