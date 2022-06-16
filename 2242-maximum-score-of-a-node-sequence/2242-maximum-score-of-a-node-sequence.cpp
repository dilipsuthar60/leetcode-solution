class Solution {
public:
    int maximumScore(vector<int>& sc, vector<vector<int>>&nums)
    {    
        int n=sc.size();
        set<pair<int,int>>dp[n+1];
        for(auto &it:nums)
        {
            dp[it[0]].insert({sc[it[1]],it[1]});
            dp[it[1]].insert({sc[it[0]],it[0]});
            if(dp[it[0]].size()>3)
            {
                dp[it[0]].erase(dp[it[0]].begin());
            }
            if(dp[it[1]].size()>3)
            {
                dp[it[1]].erase(dp[it[1]].begin());
            }
        }
        int ans=-1;
        for(auto &it:nums)
        {
            int a=it[0];
            int b=it[1];
            for(auto &t1:dp[a])
            {
                for(auto &t2:dp[b])
                {
                    if(a!=t1.second&&b!=t1.second&&t2.second!=a&&t2.second!=b&&a!=b&&t1.second!=t2.second)
                    {
                        ans=max(ans,sc[a]+sc[b]+t1.first+t2.first);
                    }
                }
            }
        }
        return ans;
    }
};