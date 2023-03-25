class Solution {
public:
    vector<int>dp[100005+10];
    void find(int node,long long &count,vector<int>&vis)
    {
        vis[node]=1;
        count++;
        for(auto it:dp[node])
        {
            if(!vis[it])
            {
                find(it,count,vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        // first creating graph
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        long long ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                // find connected component size
                long long count=0;
                find(i,count,vis);
                ans+=(count)*(n-count);
            }
        }
        // contribute in both component
        return ans/2;
    }
};