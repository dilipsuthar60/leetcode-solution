class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& nums, int src, int dst, int k) 
    {
        vector<pair<int,int>>dp[n+10];
        for(auto it:nums)
        {
            dp[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>>dis(n+1,vector<int>(k+2,INT_MAX));
        dis[src][0]=0;
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        pq.push({0,src,0});
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            int cost=temp[0];
            int node=temp[1];
            int stop=temp[2];
            if(node==dst)
            {
                return cost;
            }
            if(stop<=k)
            {
                for(auto &[nn,cc]:dp[node])
                {
                    if(cost+cc<dis[nn][stop+1])
                    {
                        dis[nn][stop+1]=cost+cc;
                        pq.push({dis[nn][stop+1],nn,stop+1});
                    }
                }
            }
        }
        return -1;
    }
};