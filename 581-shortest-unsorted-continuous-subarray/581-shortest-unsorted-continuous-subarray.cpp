class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        if(is_sorted(nums.begin(),nums.end()))
        {
            return 0;
        }
        int n=nums.size();
        int min_val=INT_MAX;
        int f=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                f=1;
            }
            if(f)
            {
                min_val=min(min_val,nums[i]);
            }
        }
        int max_val=INT_MIN;
        f=0;
        for(int i=n-2;~i;i--)
        {
            if(nums[i]>nums[i+1])
            {
                f=1;
            }
            if(f)
            {
                max_val=max(max_val,nums[i]);
            }
        }
        int start=-1;
        int end=-1;
        for(start=0;start<n;start++)
        {
            if(min_val<nums[start])
            {
                break;
            }
        }
        for( end=n-1;end>=0;end--)
        {
            if(max_val>nums[end])
            {
                break;
            }
        }
        return end-start+1;
    }
};