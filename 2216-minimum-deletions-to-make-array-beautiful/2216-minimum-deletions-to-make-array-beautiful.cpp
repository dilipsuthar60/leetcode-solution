class Solution {
public:
    int minDeletion(vector<int>& nums) 
    {
        int count=0;
        int n=nums.size();
        for(int i=0;i+1<n;i++)
        {
            if((i+count)%2==0)
            {
                if(nums[i]==nums[i+1])
                {
                    count++;
                }
            }
        }
        if((n-count)&1)
        {
            count++;
        }
        return count;
    }
};