class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) 
    {
        unordered_set<int>st(res.begin(),res.end());
        vector<int>dp[n+1];
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int count=0;
        queue<int>q;
        q.push(0);
        int vis[n+10];
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        while(q.size())
        {
            auto node=q.front();
            q.pop();
            for(auto &it:dp[node])
            {
                if(vis[it]==0&&st.find(it)==st.end())
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return accumulate(vis,vis+n+10,0);
    }
};