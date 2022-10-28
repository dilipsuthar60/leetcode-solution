class Solution {
public:
    string get_hash(string s)
    {
        vector<int>dp(26,0);
        for(int i=0;i<s.size();i++)
        {
            dp[s[i]-97]++;
        }
        string str;
        for(int i=0;i<26;i++)
        {
            str+='#'+dp[i]+'#';
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& w)
    {    
        vector<vector<string>>v;
        unordered_map<string,vector<string>>mp;
        for(auto it:w)
        {
            mp[get_hash(it)].push_back(it);
        }
        for(auto it:mp)
        {
            vector<string>val;
            for(auto x:it.second)
            {
                val.push_back(x);
            }
            v.push_back(val);
        }
        return v;
    }
};