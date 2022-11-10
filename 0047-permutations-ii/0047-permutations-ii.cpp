class Solution {
public:
    void find(vector<int>&nums,int index,unordered_map<int,int>&mp,vector<int>&curr,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        for(auto &[value,freq]:mp)
        {
            if(freq==0)
            {
                continue;
            }
            curr.push_back(value);
            mp[value]--;
            find(nums,index+1,mp,curr,ans);
            curr.pop_back();
            mp[value]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        vector<int>curr;
        vector<vector<int>>result;
        find(nums,0,mp,curr,result);
        return result;
    }
};