class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        map<int,int>mp;
        for(auto it:nums1)
        {
            mp[it[0]]+=it[1];
        }
        for(auto it:nums2)
        {
            mp[it[0]]+=it[1];
        }
        vector<vector<int>>v;
        for(auto &[a,b]:mp)
        {
            v.push_back({a,b});
        }
        return v;
    }
};