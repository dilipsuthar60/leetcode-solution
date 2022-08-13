class Solution {
public:
    bool find(vector<int>&nums,int mid,int val)
    {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=(nums[i]+mid-1)/mid;
        }
        return sum<=val;
    }
    int smallestDivisor(vector<int>& nums, int val) 
    {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,mid,val))
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