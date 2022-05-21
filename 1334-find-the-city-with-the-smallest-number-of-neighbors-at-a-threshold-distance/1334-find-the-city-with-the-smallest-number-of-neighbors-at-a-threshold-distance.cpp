class Solution {
public:
    int th;
    vector<pair<int,int>>dp[102];
    int find(int x,vector<int>&vis)
    {
        int count=0;
        queue<pair<int,int>>q;
        q.push({0,x});
        while(q.size())
        {
            auto [cost,node]=q.front();
            q.pop();
            vis[node]=1;
            if(cost>th)
            {
                continue;
            }
            for(auto &it:dp[node])
            {
                if(vis[it.first]==0&&cost+it.second<=th)
                {
                    count++;
                    q.push({cost+it.second,it.first});
                }
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int val)
    {
        th=val;
        for(auto it:edges)
        {
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],it[2]});
        }
        int max_val=n-1;
        int ans=n-1;
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            int count=find(i,vis);
            if(count<=max_val)
            {
                max_val=count;
                ans=i;
            }
        }
        return ans;
    }
};