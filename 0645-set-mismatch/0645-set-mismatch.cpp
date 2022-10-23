class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]!=nums[nums[i]-1])
            {
                // int a=nums[i];
                // int b=nums[nums[i]-1];
                // nums[i]=b;
                // nums[nums[i]-1]=a;
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return {nums[i],i+1};
            }
        }
        return {-1,-1};
    }
};