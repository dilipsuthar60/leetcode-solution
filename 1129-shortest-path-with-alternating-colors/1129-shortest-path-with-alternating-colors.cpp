class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int, list<pair<int, int>>> graph;
        for(auto i: red_edges){
            graph[i[0]].push_back(make_pair(i[1], 0));
        }
        for(auto i: blue_edges){
            graph[i[0]].push_back(make_pair(i[1], 1));
        }
        //vector<vector<bool>> visited(n, vector<bool> (2, 0));
        vector<vector<int>> distances(n, vector<int> (2, INT_MAX));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        q.push(make_pair(0, 1));
        distances[0][0] = 0;
        distances[0][1] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int edgcol = q.front().second;
            q.pop();
            for(auto i: graph[node]){
                int nodee = i.first;
                int edgcoll = i.second;
                if(distances[nodee][edgcoll] == INT_MAX && edgcoll != edgcol){
                    distances[nodee][edgcoll] = distances[node][edgcol]+1;
                    q.push(make_pair(nodee, edgcoll));
                }
            }
        }
        vector<int> ans;
        for(auto i: distances){
            if(i[0] == INT_MAX && i[1] == INT_MAX) ans.push_back(-1);
            else ans.push_back(min(i[0], i[1]));
        }
        return ans;
    }
};