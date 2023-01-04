//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   using ll=long long;
     vector<int> shortestPath(int N,int M, vector<vector<int>>& nums)
     {
        // code here
        vector<vector<pair<ll,ll>>>dp(N);
         for(auto it:nums)
        {
            dp[it[0]].push_back({it[1],it[2]});
            // dp[it[1]].push_back({it[0],it[2]});
        }
        int x=0;
        vector<int>dis(N,1e9);
         priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0ll,x});
        vector<int>vis(N,0);
        dis[x]=0ll;
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            ll cost=temp.first;
            ll node=temp.second;
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            for(auto &it:dp[node])
            {
                if(dis[it.first]>dis[node]+it.second)
                {
                    dis[it.first]=dis[node]+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(dis[i]==1e9)
            {
                dis[i]=-1;
            }
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