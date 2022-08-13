class Solution 
{
public:
    bool find(vector<int>&nums,int mid,int val)
    {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%mid==0)
            {
                sum=sum+nums[i]/mid-1;
            }
            else
            {
                sum=sum+nums[i]/mid;
            }
        }
        return sum<=val;
    }
    int minimumSize(vector<int>& nums, int mx) 
    {    
        int l=1;
        long long  r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,mid,mx))
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