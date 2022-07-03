class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int n=nums.size();
        int inc=1;
        int dec=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                inc=dec+1;
            }
            else if(nums[i-1]>nums[i])
            {
                dec=inc+1;
            }
        }
        return max(inc,dec);
    }
};