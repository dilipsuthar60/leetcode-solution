class Solution {
public:
    void find(vector<int>&nums,vector<vector<int>>&v,vector<int>&res,int index)
    {
        v.push_back(res);
        for(int i=index;i<nums.size();i++)
        {
            res.push_back(nums[i]);
            find(nums,v,res,i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>v;
        vector<int>res;
        find(nums,v,res,0);
        return v;
    }
};