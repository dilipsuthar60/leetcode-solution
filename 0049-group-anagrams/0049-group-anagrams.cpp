class Solution {
public:
    string hash(string &s)
    {
        int dp[26];
        memset(dp,0,sizeof(dp));
        string hash_value="";
        for(int i=0;i<s.size();i++)
        {
            dp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            hash_value+=to_string(dp[i])+"##";
        }
        return hash_value;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto it:strs)
        {
            string new_string=it;
            sort(new_string.begin(),new_string.end());
            mp[new_string].push_back(it);
        }
        for(auto&[a,b]:mp)
        {
            ans.push_back(b);
        }
        return ans;
    }
};