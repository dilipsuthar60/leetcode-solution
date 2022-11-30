class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        for(auto &it:arr)
        {
            mp[it]++;
        }
        unordered_set<int>s;
        for(auto &[a,b]:mp)
        {
            s.insert(b);
        }
        return s.size()==mp.size();
    }
};