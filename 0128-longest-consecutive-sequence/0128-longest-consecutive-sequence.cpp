class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
       sort(nums.begin(),nums.end());
        int ans=0;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]!=nums[i])
            {
                if(nums[i-1]==nums[i]-1)
                {
                    count++;
                }
                else
                {
                        ans=max(ans,count);
                        count=1;
                }
            }
        }
        return max(ans,count);
    }
};