class Solution {
public:
    int rob(vector<int>& nums)    
    {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int prev1=0;
        int prev2=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
               prev2=nums[i];
            }
            else if(i==1)
            {
                prev1=max(nums[i],nums[i-1]);
            }
            else
            {
                int temp=prev1;
                prev1=max(nums[i]+prev2,prev1);
                prev2=temp;
            }
        }
        return prev1;
    }
};