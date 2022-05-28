class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& nums)
    {
        vector<long long>dp(n+1);
        for(auto &it:nums)
        {
            dp[it[0]]++;
            dp[it[1]]++;
        }
        long long sum=0;
       sort(dp.rbegin(),dp.rend());
        for(int i=0;i<n;i++)
        {
            sum+=(n-i)*(dp[i]);
        }
        return sum;
    }
};