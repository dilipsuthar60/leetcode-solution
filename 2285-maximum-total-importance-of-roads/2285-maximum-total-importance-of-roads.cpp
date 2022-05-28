class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& nums)
    {
        vector<vector<long long>>dp(n+1);
        for(auto &it:nums)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<pair<long long,long long>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({dp[i].size(),i});
        }
        vector<long long>value(n+1,0);
        long long val=n;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++)
        {
            value[v[i].second]=val--;
        }
        long long sum=0;
        for(auto &it:nums)
        {
            sum+=(value[it[0]]+value[it[1]]);
        }
        return sum;
    }
};