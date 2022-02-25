class Solution {
public:
    string findReplaceString(string s, vector<int>& ind, vector<string>& source, vector<string>& target) 
    {
        unordered_map<int,pair<int,string>>mp;
        for(int i=0;i<ind.size();i++)
        {
            if(s.substr(ind[i],source[i].size())==source[i])
            {
                mp[ind[i]]={source[i].size(),target[i]};
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(i)!=mp.end())
            {
                ans+=mp[i].second;
                i+=mp[i].first-1;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};