class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int first) 
    {
        vector<vector<pair<int,int>>>dp(n+1);
        for(auto it:meet)
        {
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],it[2]});
        }
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        // queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,first});
        while(q.size())
        {
            auto [time,node]=q.top();
            q.pop();
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            for(auto &[new_node,new_time]:dp[node])
            {
                if((vis[new_node]==0)&&time<=new_time)
                {
                    q.push({new_time,new_node});
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};