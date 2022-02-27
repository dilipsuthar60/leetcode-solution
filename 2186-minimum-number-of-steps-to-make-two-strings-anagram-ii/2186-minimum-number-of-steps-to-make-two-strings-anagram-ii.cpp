class Solution {
public:
    int minSteps(string s, string t) 
    {
        vector<int>dp(26,0);
        for(int i=0;i<s.size();i++)
        {
            dp[s[i]-97]++;
        }
        for(int i=0;i<t.size();i++)
        {
            dp[t[i]-97]--;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            count+=abs(dp[i]);
        }
        return count;
    }
};