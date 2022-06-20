class Solution
{
    public:
    int n;
    int m;
    int dp[51][51][51];
    int mod = 1e9 + 7;
    int prefix[60][60];
    int find(vector<string> &mat, int r, int c, int k)
    {
        if (k == 1)
        {
            return prefix[r][c]>0;
        }
        if (dp[r][c][k] != -1)
        {
            return dp[r][c][k];
        }
        long long ans = 0;
        for (int i = r + 1; i < n; i++)
        {
            if (prefix[r][c] - prefix[i][c] > 0)
            {
                ans += find(mat, i, c, k - 1);
            }
        }
        for (int j = c + 1; j < m; j++)
        {
            if (prefix[r][c] - prefix[r][j] > 0)
            {
                ans += find(mat, r, j, k - 1);
            }
        }
        return dp[r][c][k] = ans % mod;
    }
    int ways(vector<string> &mat, int k)
    {
        memset(dp, -1, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        n = mat.size();
        m = mat[0].size();
        cout<<~(-1)<<endl;
        for (int i = n - 1; ~i; i--)
        {
            for (int j = m - 1; ~j; j--)
            {
                prefix[i][j] = (mat[i][j] == 'A') + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1];
            }
        }
        return find(mat, 0, 0, k);
    }
};