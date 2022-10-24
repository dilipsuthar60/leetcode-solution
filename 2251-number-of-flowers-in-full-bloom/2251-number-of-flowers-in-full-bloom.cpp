class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>&nums, vector<int>& p) 
    {
        map<int,int>mp;
        mp.insert({0,0});
        for(auto it:nums)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sum=0;
        for(auto &it:mp)
        {
            sum+=it.second;
            it.second=sum;
        }
        vector<int>ans;
        for(auto it:p)
        {
            auto val=mp.upper_bound(it);
            ans.push_back(prev(val)->second);
        }
        return ans;
    }
};