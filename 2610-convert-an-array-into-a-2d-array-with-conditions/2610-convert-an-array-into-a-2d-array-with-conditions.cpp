class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int row=0;
        for(auto &&[a,b]:mp)
        {
            row=max(row,b);
        }
        vector<vector<int>>ans(row);
        for(auto &[a,b]:mp)
        {
            int index=0;
            while(b--)
            {
                ans[index++].push_back(a);
            }
        }
        return ans;
    }
};