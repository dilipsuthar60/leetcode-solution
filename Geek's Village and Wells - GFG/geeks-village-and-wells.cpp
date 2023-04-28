//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code her
        vector<vector<int>>dp(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='W')
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        int level=2;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(auto it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&c[nx][ny]!='N'&&vis[nx][ny]==0)
                    {
                        vis[nx][ny]=1;
                        dp[nx][ny]=level;
                        q.push({nx,ny});
                    }
                }
            }
            level+=2;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='H'&&dp[i][j]==0)
                {
                    dp[i][j]=-1;
                }
                if(c[i][j]=='.')
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends