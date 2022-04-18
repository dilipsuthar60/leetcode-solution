class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        vector<vector<int>>adj(n+1);
        for(int i = 1; i<n; i++){
            int nxt = parent[i];
            if(s[nxt]!=s[i]){
                int x = i; int y = nxt;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
        }
        int ans = 0;
        queue<int>q;
        vector<bool>vis(n+1);
        vector<bool>vis2(n+1);
        vector<int>dis(n+1);
        vector<int>dis2(n+1);
        for(int i = 1; i<=n; i++){
            if(vis[i])continue;
            vis[i] = true;
            q.push(i);
            int dist = 0; int node = 1;
            while(q.size()){
                int cur = q.front(); q.pop();
                for(int nxt: adj[cur]){
                    if(vis[nxt])continue;
                    vis[nxt] = true;
                    q.push(nxt);
                    dis[nxt] = dis[cur]+1;
                    if(dis[nxt]>dist){
                        dist = dis[nxt];
                        node = nxt;
                    }
                }
            }
            q.push(node);
            vis2[node] = true;
            while(q.size()){
                int cur = q.front(); q.pop();
                for(int nxt: adj[cur]){
                    if(vis2[nxt])continue;
                    dis2[nxt] = dis2[cur]+1;
                    q.push(nxt);
                    vis2[nxt] = true;
                    ans = max(ans,dis2[nxt]);
                }
            }
        }
        return ans+1;
    }
};