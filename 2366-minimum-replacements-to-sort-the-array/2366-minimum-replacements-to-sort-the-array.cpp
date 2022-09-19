class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        int n=nums.size();
        long long count=0;
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=prev)
            {
                prev=nums[i];
            }
            else
            {
                long long option=nums[i]/prev;
                if(nums[i]%prev==0)
                {
                    count+=option-1;
                }
                else
                {
                    count+=option;
                    prev=nums[i]/(option+1);
                }
            }
        }
        return count;
    }
};