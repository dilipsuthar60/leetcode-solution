class Solution
{
    public:
        int n;
    int mod = 1e9 + 7;
    long long dp[1001][1001];
    bool yes(char & ch)
    {
        return (ch == '2') || (ch == '3') || (ch == '5') || (ch == '7');
    }
    long long find(string &s, int index, int k, int &len)
    {
        if (index + k * len > n || !yes(s[index]))
            return 0;
        if (dp[index][k] != -1)
        {
            return dp[index][k] % mod;
        }
        if (k == 1)
        {
            if (yes(s[index]) && (n - index) >= len && (!yes(s[n - 1])))
            {
                return 1ll;
            }
        }
        long long ans = 0;
        for (int i = index + len - 1; i < n; i++)
        {
            if ((!yes(s[i])))
            {
                ans += find(s, i + 1, k - 1, len) % mod;
            }
        }
        return dp[index][k] = ans % mod;
    }
    int beautifulPartitions(string s, int k, int minLength)
    {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return find(s, 0, k, minLength) % mod;
    }
};