class Solution {
public:
    bool isAlienSorted(vector<string>& w, string o)
    {
        vector<int>dp(26,0);
        for(int i=0;i<o.size();i++)
        {
            dp[o[i]-97]=i;
        }
        for(auto &it:w)
        {
            string s="";
            for(int i=0;i<it.size();i++)
            {
                s.push_back(char(dp[it[i]-'a']));
            }
            it=s;
        }
        return is_sorted(w.begin(),w.end());
    }
};