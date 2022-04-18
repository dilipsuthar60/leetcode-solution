class Solution {
public:
    vector<vector<int>>dp;
    pair<int,int>bfs(int x,vector<int>&vis)
    {
        queue<int>q;
        int level=0;
        q.push(x);
        vis[x]++;
        int far_node=x;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                far_node=temp;
                for(auto it:dp[temp])
                {
                    if(vis[it]!=vis[temp])
                    { 
                      vis[it]++;
                      q.push(it);
                    }
                }
            }
            level++;
        }
        return {far_node,level};
    }
    int longestPath(vector<int>& parent, string s) 
    {
        int n=parent.size();
        dp.resize(n+1);
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[parent[i]])
            {
                dp[parent[i]].push_back(i);
                dp[i].push_back(parent[i]);
            }
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                auto [far_node,d]=bfs(i,vis);
                 auto [node,dis]=bfs(far_node,vis);
                ans=max(ans,dis);
            }
        }
        return ans;
    }
};