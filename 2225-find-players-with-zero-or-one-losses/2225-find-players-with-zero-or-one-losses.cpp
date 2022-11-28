class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>&nums)
    {
        int n=nums.size();
        unordered_map<int,int>mp1,mp2;
        for(auto &it:nums)
        {
            mp1[it[0]]++;
            mp2[it[1]]++;
        }
        vector<int>first,second;
        for(auto &[a,b]:mp1)
        {
            if(mp2.find(a)==mp2.end())
            {
                first.push_back(a);
            }
        }
        for(auto &[a,b]:mp2)
        {
            if(b==1)
            {
                second.push_back(a);
            }
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        return {first,second};
    }
};