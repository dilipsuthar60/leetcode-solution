class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int cost=0;
        int n=nums.size();
        int m=nums[0].size();
        vector<multiset<int,greater<int>>>v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v[i].insert(nums[i][j]);
            }
        }
        while(m--)
        {
            int max_value=0;
            for(int i=0;i<n;i++)
            {
                max_value=max(max_value,*v[i].begin());
            }
            cost+=max_value;
            for(int i=0;i<n;i++)
            {
                v[i].erase(v[i].begin());
            }
        }
        return cost;
    }
};