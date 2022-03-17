class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>&nums) 
    {
        using ll=long long;
        vector<vector<ll>>dp[n+10];
        for(auto it:nums)
        {
            ll x=it[0];
            ll y=it[1];
            ll wt=it[2];
            dp[x].push_back({y,wt});
            dp[y].push_back({x,wt});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll>path(n,0);
        vector<ll>dis(n,1e17);
        path[0]=1;
        dis[0]=0;
        pq.push({0,0});
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            ll wt=temp.first;
            ll node=temp.second;
            for(auto it:dp[node])
            {
                ll node1=it[0];
                ll wt1=it[1];
                 if(dis[node1]>wt+wt1)
                {
                    dis[node1]=wt+wt1;
                    path[node1]=path[node];
                    pq.push({dis[node1],node1});
                }
                else  if(dis[node1]==wt+wt1)
                {
                    path[node1]=(path[node1]+path[node])%mod;
                }
            }
        }
        return path[n-1];
    }
};