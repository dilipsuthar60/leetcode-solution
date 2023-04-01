class Solution {
public:
    vector<int> gr[5000];
  int find(int n)
{
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) 
    {
        vector<int> dist(n, (int)(1e9));
 
        vector<int> par(n, -1);
 
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {

            int x = q.front();
            q.pop();
            for (int child : gr[x]) {
                if (dist[child] == (int)(1e9)) {
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                }

                else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }
 
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}
 
    int findShortestCycle(int N, vector<vector<int>>& edges) 
    {
        for(auto it:edges)
        {
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        return find(N);
    }
};