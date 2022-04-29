class Solution {
public:
    vector<vector<int>>dp;
    bool find(int x,vector<int>&vis)
    {
        queue<pair<int,int>>q;
        q.push({x,0});
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            if(vis[temp.first]!=-1)
            {
                if(vis[temp.first]!=temp.second)
                {
                    return false;
                }
            }
            else
            {
                vis[temp.first]=temp.second;
            }
            for(auto it:dp[temp.first])
            {
                if(vis[it]==-1)
                {
                    q.push({it,temp.second+1});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        dp=graph;
        int n=graph.size();
         vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                bool x=find(i,vis);
                if(x==false)
                {
                    return false;
                }
                    
            }
        }
        return true;
    }
};