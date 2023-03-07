class Solution {
public:
    int vis[1100];
    int ans=0;
    vector<pair<int,int>>dp[1100];
    void find(int node,vector<int>&nums,int &maxtime,int current_time,int total)
    {
        if(current_time>maxtime)
        {
            return ;
        }
        if(vis[node]==0)
        {
            total+=nums[node];
        }
        vis[node]++;
        if(node==0)
        {
            ans=max(ans,total);
        }
        for(auto it:dp[node])
        {
            int new_time=it.second+current_time;
            find(it.first,nums,maxtime,new_time,total);
        }
        vis[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) 
    {
        memset(vis,0,sizeof(dp));
        for(auto &it:edges)
        {
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],it[2]});
        }
        find(0,values,maxTime,0,0);
        return ans;
    }
};