class Solution {
public:
    bool checkOddCycle(int node,vector<int>&vis,vector<vector<int>>&dp)
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;
        vector<int>col(vis.size(),0);
        col[node]=1;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            for(auto &it:dp[temp])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push(it);
                    col[it]=(col[temp]^1);
                }
                else if(col[it]==col[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    int findFarDistance(int node,int n,vector<vector<int>>&dp)
    {
        queue<int>q;
        q.push(node);
        vector<int>vis(n+1,0);
        vis[node]=1;
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                for(auto it:dp[temp])
                {
                    if(vis[it]==0)
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            level++;
        }
        return level;
    }
    int findMaxOfAllNodeGroup(int node,int n,vector<int>&vis, vector<int>&dis,vector<vector<int>>&dp)
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;
        int maxValue=0;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            maxValue=max(maxValue,dis[temp]);
            for(auto it:dp[temp])
            {
                if(vis[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return maxValue;
        
    }
    int magnificentSets(int n, vector<vector<int>>&edges) 
    {
        vector<vector<int>>dp(n+1);
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(!checkOddCycle(i,vis,dp))
                {
                    return -1;
                }
            }
        }
        vector<int>dis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dis[i]=findFarDistance(i,n,dp);
        }
        vis=vector<int>(n+1,0);
        int group=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                group+=findMaxOfAllNodeGroup(i,n,vis,dis,dp);
            }
        }
        return group;
    }
};