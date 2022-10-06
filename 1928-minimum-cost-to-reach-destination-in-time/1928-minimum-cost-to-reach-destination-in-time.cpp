class Solution
{
public:
    int minCost(int maxtime,vector<vector<int>>&nums,vector<int>&fee) 
    {
        int n=fee.size();
        vector<pair<int,int>>dp[n+100];
        vector<int>dis(n+1000,INT_MAX);
        for(const auto &it:nums)
        {
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        pq.push({fee[0],0,0});
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            int f=temp[0];
            int time=temp[1];
            int node=temp[2];
            if(node==n-1)
            {
                return f;
            }
            for(const auto &it:dp[node])
            {
                int new_time=time+it.second;
                if(new_time<=maxtime&&dis[it.first]>(time+it.second))
                {
                   dis[it.first]=new_time;
                   pq.push({f+fee[it.first],new_time,it.first});
                }
            }
        }
        return -1;
    }
};