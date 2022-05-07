class Solution {
public:
    const int mod=1e9+7;
    int dp2[100000];
    int find(int s,int e,vector<int>&dis,vector<pair<int,int>>dp[])
    {
        if(1==e)
        {
            return 1;
        }
        if(dp2[e]!=-1)
        {
            return dp2[e];
        }
        int w1,w2;
        int ans=0;
        for(auto it:dp[e])
        {
             w1=dis[e];
             w2=dis[it.first];
            if(w2>w1)
            {
                ans=(ans+find(s,it.first,dis,dp))%mod;
            }
        }
        return dp2[e]=ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& nums) 
    {
        memset(dp2,-1,sizeof(dp2));
        vector<pair<int,int>>dp[n+10];
        for(auto it:nums)
        {
            int x=it[0];
            int y=it[1];
            int w=it[2];
            dp[x].push_back({y,w});
            dp[y].push_back({x,w});
        }
        vector<int>vis(n+1,0);
        vector<int>dis(n+2,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,n});
        dis[n]=0;
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            int wt=temp.first;
            int node=temp.second;
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            for(auto it:dp[node])
            {
                int nn=it.first;
                int nw=it.second;
                if(dis[nn]>dis[node]+nw)
                {
                    dis[nn]=dis[node]+nw;
                    pq.push({dis[nn],nn});
                }
            }
        }
        return find(1,n,dis,dp);
    }
};