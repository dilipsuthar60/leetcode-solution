class Solution {
public:
    bool find(vector<int>&v,int mid)
    {
        int n=v.size();
        vector<long long>nums(v.begin(),v.end());
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>mid)
            {
                nums[i-1]+=abs(nums[i]-mid);
            }
        }
        return nums[0]<=mid;
    }
    int minimizeArrayValue(vector<int>& nums) 
    {
        int ans=*max_element(nums.begin(),nums.end());
        int l=0;
        int r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,mid))
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