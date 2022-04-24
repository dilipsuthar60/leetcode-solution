class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        map<int,int>mp;
        for(auto it:nums)
        {
            for(auto t:it)
            {
                mp[t]++;
            }
        }
        vector<int>ans;
        int n=nums.size();
        for(auto it:mp)
        {
            if(it.second==n)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};