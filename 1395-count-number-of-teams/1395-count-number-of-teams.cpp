class Solution {
public:
    int numTeams(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        for(int i=1;i<n-1;i++)
        {
            int left_small,left_big,right_small,right_big;
            left_small=left_big=right_small=right_big=0;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    left_small++;
                }
                if(nums[j]>nums[i])
                {
                    left_big++;
                }
            }
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j])
                {
                    right_big++;
                }
                if(nums[i]>nums[j])
                {
                    right_small++;
                }
            }
            count+=left_small*right_big+left_big*right_small;
        }
        return count;
    }
};