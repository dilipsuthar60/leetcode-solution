class Solution {
public:
     long long find(string &s, string t) {
        long long m = t.length(), n = s.length();
        vector<vector<long long>> dp(m + 1, vector<long long> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0ll);
        return dp[m][n];
    }
    long long numberOfWays(string s) {
       long long ans=find(s,"101")+find(s,"010");
        return ans;
    }
};