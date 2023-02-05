class Solution {
public:
    bool find(vector<int>&nums,int k,int mid)
    {
        int count=0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(nums[i]<=mid)
            {
                count++;
                i++;
            }
        }
        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int ans=0;
        int l=0;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,k,mid))
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