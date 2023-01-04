//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
// class Solution {
//   public:
//      vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
//         // code here
//     }
// };

class Solution {
  public:
  vector<int> vis;
  vector<int> dis;
  stack<int> st;
  void topo(int node,vector<pair<int,int>>adj[])
  {
      if(vis[node]) return;
      vis[node]=1;
      for(auto x:adj[node])
      {
          topo(x.first,adj);
      }
      st.push(node);
      
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
     {
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
       
        vis.resize(N,0);
         for(int i=0;i<N;i++)
         {
             if(vis[i]==0) 
             {topo(i,adj);
             }
         }
        dis.resize(N,1e9);
        dis[0]=0;
        while(st.size())
        {
             
                int j=st.top();
                st.pop();
                if(dis[j]!=1e9)
                for(auto x:adj[j])
                {
                    if(dis[x.first]>x.second+dis[j]) dis[x.first]=x.second+dis[j];
                }
            
        }
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
         
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends