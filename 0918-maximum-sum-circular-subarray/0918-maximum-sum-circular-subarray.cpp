class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int sum=0;
        int max_sum=nums[0];
        int min_sum=nums[0];
        int curr_max=0;
        int curr_min=0;
        for(int i=0,n=nums.size();i<n;i++)
        {
            sum+=nums[i];
            curr_max=max(curr_max+nums[i],nums[i]);
            max_sum=max(curr_max,max_sum);
            curr_min=min(curr_min+nums[i],nums[i]);
            min_sum=min(curr_min,min_sum);
        }
        return max_sum>0?max(max_sum,sum-min_sum):max_sum;
    }
};