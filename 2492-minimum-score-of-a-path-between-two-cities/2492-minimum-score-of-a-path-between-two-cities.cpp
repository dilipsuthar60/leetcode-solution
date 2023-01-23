class Solution {
public:
    int minScore(int n, vector<vector<int>>&nums) 
    {
        vector<vector<pair<int,int>>>dp(n+10);
        for(auto &it:nums)
        {
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],it[2]});
        }
        queue<int>q;
        int cost=INT_MAX;
        vector<int>vis(n+10,0);
        q.push(1);
        vis[1]=1;
        while(q.size())
        {
            int node=q.front();
            q.pop();
            for(auto &it:dp[node])
            {
                cost=min(cost,it.second);
                if(vis[it.first]==0)
                {
                    q.push(it.first);
                    vis[it.first]=1;
                }
            }
        }
        return cost;
    }
};