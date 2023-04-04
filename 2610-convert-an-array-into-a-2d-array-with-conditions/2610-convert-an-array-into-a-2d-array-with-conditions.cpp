class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(const auto &it:nums)
        {
            mp[it]++;
        }
        int row=0;
        for(const auto &[a,b]:mp)
        {
            row=max(row,b);
        }
        vector<vector<int>>ans(row);
        for(const auto &[a,b]:mp)
        {
            int index=0;
            for(int i=0;i<b;i++)
            {
                ans[index++].push_back(a);
            }
        }
        return ans;
    }
};