//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  vector<vector<int>>mat;
  vector<int>parent;
  int find(int x)
  {
      if(x==parent[x])
      {
          return x;
      }
      return parent[x]=find(parent[x]);
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &q) {
        // code here
        parent=vector<int>(n*m+10,-1);
        mat=vector<vector<int>>(n,vector<int>(m,0));
        vector<int>ans;
        int count=0;
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto it:q)
        {
            int x=it[0];
            int y=it[1];
            int hash=x*m+y;
            if(parent[hash]!=-1)
            {
                ans.push_back(count);
                continue;
            }
            parent[hash]=hash;
            count++;
            for(auto dir:d)
            {
                int nx=x+dir.first;
                int ny=y+dir.second;
                int new_hash=nx*m+ny;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&parent[new_hash]!=-1)
                {
                    int lx=find(hash);
                    int ly=find(new_hash);
                    if(lx!=ly)
                    {
                        count--;
                        parent[ly]=lx;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends