class Solution {
public:
    vector<int>dp[100006];
    int vis[100006];
    void find(int node,unordered_set<int>&st)
    {
        vis[node]=1;
        for(auto &it:dp[node])
        {
            if(!vis[it]&&st.find(it)==st.end())
            {
                find(it,st);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) 
    {
        unordered_set<int>st(res.begin(),res.end());
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        find(0,st);
        return accumulate(vis,vis+n,0);
    }
};