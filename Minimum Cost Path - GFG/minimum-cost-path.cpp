// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>&mat) 
    {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        int dis[n][m],vis[n][m];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[i][j]=1e9;
            }
        }
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({mat[0][0],0});
        dis[0][0]=mat[0][0];
        int cost,x,y;
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            cost=temp.first;
            x=temp.second/m;
            y=temp.second%m;
            if(vis[x][y])
            {
                continue;
            }
            vis[x][y]=1;
            for(auto &it:dir)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&dis[nx][ny]>dis[x][y]+mat[nx][ny])
                {
                    dis[nx][ny]=dis[x][y]+mat[nx][ny];
                    pq.push({dis[nx][ny],nx*m+ny});
                }
            }
        }
        return dis[n-1][m-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends