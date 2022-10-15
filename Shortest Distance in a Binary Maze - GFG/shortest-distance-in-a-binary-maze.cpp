//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, pair<int, int> s,
                     pair<int, int> d) {
       int n=mat.size();
       int m=mat[0].size();
       queue<int>q;
       q.push(s.first*m+s.second);
       int level=0;
       vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
       mat[s.first][s.second]=-1;
       while(q.size())
       {
           int size=q.size();
           while(size--)
           {
               auto temp=q.front();
               q.pop();
               int x=temp/m;
               int y=temp%m;
            //   cout<<x<<"  "<<y<<endl;
               if(x==d.first&&y==d.second)
               {
                   return level;
               }
               for(auto it:dir)
               {
                   int nx=x+it.first;
                   int ny=y+it.second;
                   if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]==1)
                   {
                       q.push(nx*m+ny);
                       mat[nx][ny]=-1;
                   }
               }
           }
           level++;
       }
    //   for(int i=0;i<n;i++)
    //   {
    //       for(int j=0;j<m;j++)
    //       {
    //           cout<<mat[i][j]<<" ";
    //       }
    //       cout<<endl;
    //   }
       return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends