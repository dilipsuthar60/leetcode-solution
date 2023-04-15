class Graph {
public:
      int n;
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->adj.resize(n);
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];
            adj[from].push_back({to, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
         int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        adj[from].push_back({to, cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>vis(n,0);
   vector<int> dist(n, numeric_limits<int>::max());
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            if (currNode == node2) {
                return currDist;
            }
            if(vis[currNode])
            {
                continue;
            }
            vis[currNode]=1;
            for (const auto& neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int edgeCost = neighbor.second;
                int nextDist = currDist + edgeCost;

                if (nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    pq.push({nextDist, nextNode});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */