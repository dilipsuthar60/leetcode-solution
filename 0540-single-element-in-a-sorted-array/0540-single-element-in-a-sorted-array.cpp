class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int n=nums.size();
        if(n==1)
        {
            return nums.front();
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid-1]==nums[mid])
            {
                int left_count=(mid-l+1);
                if(left_count%2==0)
                {
                    l=mid+1;
                }
                else
                {    
                    r=mid-2;
                }
            }
            else if(nums[mid+1]==nums[mid])
            {
                int right_count=(r-mid+1);
                if(right_count%2==0)
                {
                   r=mid-1;
                }
                else
                {
                    l=mid+2;
                }
            }
        }
        return -1;
    }
};