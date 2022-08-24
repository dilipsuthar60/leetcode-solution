class Solution {
public:
    vector<vector<int>>dp;
    vector<int>subtree;
    void subtree_sub(int node,int p)
    {
        for(auto &it:dp[node])
        {
            if(it!=p)
            {
                subtree_sub(it,node);
                subtree[node]+=subtree[it];
            }
        }
    }
    int find(int node,int n)
    {
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        int level=0;
        int root=0;
        vis[0]=1;
        while(q.size())
        {
            int size=q.size();
            root+=level*size;
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                for(auto &it:dp[temp])
                {
                    if(vis[it]==0)
                    {
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            level++;
        }
        return root;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        subtree=vector<int>(n+1,1);
        dp=vector<vector<int>>(n+10);
        vector<int>ans(n,0);
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        subtree_sub(0,-1);
        ans[0]=find(0,n);
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0]=1;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                int temp=q.front();
                q.pop();
                for(auto &it:dp[temp])
                {
                    if(vis[it]==0)
                    {
                        vis[it]=1;
                        ans[it]=ans[temp]-(subtree[it])+(n-subtree[it]);
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};