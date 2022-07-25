class Solution
{
    public:
        int n, m;
    int dp[201][201]{0};
    int find(vector<vector < int>> &mat, int i, int j, int prev)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({ find(mat, i - 1, j, mat[i][j]),
            find(mat, i + 1, j, mat[i][j]),
            find(mat, i, j - 1, mat[i][j]),
            find(mat, i, j + 1, mat[i][j]) });
    }
    int longestIncreasingPath(vector<vector < int>> &mat)
    {
        n = mat.size();
        m = mat[0].size();
        int ans = 0;
        // memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, find(mat, i, j, -1));
            }
        }
        return ans;
    }
};