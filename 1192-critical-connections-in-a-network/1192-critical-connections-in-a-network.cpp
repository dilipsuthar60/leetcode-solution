class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>>dp;
    void find(int u,vector<int>&parent,vector<int>&dis,vector<int>&low,vector<bool>&vis)
    {
        static int time=0;
        dis[u]=time;
        low[u]=time;
        vis[u]=true;
        time++;
        for(auto &it:dp[u])
        {
            if(parent[u]==it)
            {
                continue;
            }
            else if(vis[it]==true)
            {
                low[u]=min(low[u],dis[it]);
            }
            else
            {
                parent[it]=u;
                find(it,parent,dis,low,vis);
                low[u]=min(low[u],low[it]);
                if(low[it]>dis[u])
                {
                    ans.push_back({it,u});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>&mat)
    {
        vector<int>parent(n+1,-1),dis(n+1),low(n+1,0);
        vector<bool>vis(n+1,false);
        dp.resize(n+1);
        for(auto it:mat)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        find(0,parent,dis,low,vis);
        return ans;
    }
};