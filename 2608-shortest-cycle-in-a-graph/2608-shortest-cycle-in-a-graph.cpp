class Solution {
public:
    vector<vector<int>>dp;
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        dp=vector<vector<int>>(n+1);
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            vector<int>dis(n,-1);
            queue<pair<int,int>>q;
            q.push({i,-1});
            dis[i]=0;
            while(q.size())
            {
                auto [node,parent]=q.front();
                q.pop();
                for(auto it:dp[node])
                {
                    if(dis[it]==-1)
                    {
                        dis[it]=dis[node]+1;
                        q.push({it,node});
                    }
                    else if(it!=parent)
                    {
                        ans=min(ans,dis[node]+dis[it]+1);
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};