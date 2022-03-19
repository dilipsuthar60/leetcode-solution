class Solution {
public:
    long long find(string &s,string &t)
    {
        int m = t.length(), n = s.length();
        vector<vector<long long>> dp(m + 1, vector<long long> (n + 1, 0ll));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0ll);
        return dp[m][n];
    }
    long long maximumSubsequenceCount(string text, string pattern) 
    {
        string s1=pattern[0]+text;
        string s2=text+pattern[1];
        return max({find(s1,pattern),find(s2,pattern)});
    }
};