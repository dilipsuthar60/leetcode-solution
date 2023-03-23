class Solution {
public:
    void find(int x,vector<vector<int>>&v,vector<bool>&mark)
    {
        mark[x]=true;
        for(auto it:v[x])
        {
            if(mark[it]==false)
            {
                find(it,v,mark);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& nums) 
    {
        if(nums.size()<n-1)
        {
            return -1;
        }
        vector<vector<int>>v(n);
        for(auto it:nums)
        {
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<bool>mark(n,false);
        for(int i=0;i<n;i++)
        {
            if(mark[i]==false)
            {
                find(i,v,mark);
                count++;
            }
        }
        return count-1;
    }
};
/*
class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};
*/