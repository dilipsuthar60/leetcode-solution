//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int mod=1e9+7;
vector<vector<long long>>dp;
long long find(vector<vector<int>>&mat,int i,int j)
{
    if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]==1)
    {
        return 0;
    }
    if(i==mat.size()-1&&j==mat[0].size()-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j]%mod;
    }
    long long left=find(mat,i+1,j);
    long long right=find(mat,i,j+1);
    return dp[i][j] =(left+right)%mod;
}
	int FindWays(int n, int m, vector<vector<int>>blocked){
	    // Code here
	    dp=vector<vector<long long>>(n+1,vector<long long>(m+1,-1));
	   vector<vector<int>>mat(n,vector<int>(m,0));
	   for(auto &it:blocked)
	   {
	       mat[it[0]-1][it[1]-1]=1;
	   }
	  return find(mat,0,0)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends