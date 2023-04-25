//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int count=0;
vector<int>dp[100];
vector<int>vis;
void find(int node,int t)
{
    if(node==t)
    {
        count++;
    }
    for(auto &it:dp[node])
    {
        if(vis[it]==0)
        {
            vis[it]=1;
            find(it,t);
            vis[it]=0;
        }
    }
}
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    count=0;
	    vis=vector<int>(100,0);
	    for(auto it:edges)
	    {
	        dp[it[0]].push_back(it[1]);
	       // dp[it[1]].push_back(it[0]);
	    }
	    find(s,d);
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends