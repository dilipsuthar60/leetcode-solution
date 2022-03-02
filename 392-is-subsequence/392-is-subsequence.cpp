class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        vector<vector<int>>dp(26);
        for(int i=0;i<t.size();i++)
        {
            dp[t[i]-'a'].push_back(i);
        }
        int x=-1;
        for(int i=0;i<s.size();i++)
        {
            auto it=upper_bound(dp[s[i]-'a'].begin(),dp[s[i]-'a'].end(),x);
            if(it==dp[s[i]-'a'].end())
            {
                return false;
            }
            else
            x=*it;
        }
        return true;
    }
};