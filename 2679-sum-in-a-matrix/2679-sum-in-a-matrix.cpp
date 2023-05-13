class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int cost=0;
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++)
        {
            sort(nums[i].begin(),nums[i].end());
        }
        while(!nums[0].empty())
        {
            int value=0;
            for(int i=0;i<nums.size();i++)
            {
                value=max(value,nums[i].back());
            }
            cost+=value;
            for(int i=0;i<nums.size();i++)
            {
                nums[i].pop_back();
            }
        }
        return cost;
    }
};