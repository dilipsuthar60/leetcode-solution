class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& rows, int k) {
        vector<int> dp(k + 1, -1e9);
    dp[0] = 0;
        for(auto &it:rows)
        {
            reverse(it.begin(),it.end());
        }
    for (const auto& nums : rows) {
        int n = nums.size();
        auto dpc = dp;

        for (int i = 1; i <= k; ++i) {
            int sum = 0;
            for (int j = 1; j <= min(i, n); ++j)
                dpc[i] = max(dpc[i], (sum += nums[n - j]) + dp[i - j]);
        }

        dp = dpc;
    }

    return dp[k];
    }
};