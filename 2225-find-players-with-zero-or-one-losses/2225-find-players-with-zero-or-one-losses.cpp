class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) 
    {
        map<int,int>mp1,mp2;
        set<int>s;
        for(auto &it:nums)
        {
            mp1[it[0]]++;
            mp2[it[1]]++;
            s.insert(it[1]);
        }
        vector<int>win,lost;
        for(auto &it:mp1)
        {
            if(s.find(it.first)==s.end())
            {
                win.push_back(it.first);
            }
        }
        for(auto &it:mp2)
        {
            if(it.second==1)
            {
                lost.push_back(it.first);
            }
        }
        return {win,lost};
    }
};