//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>>dp;
  void find(int node,vector<vector<int>>&val,int p=-1)
  {
      for(auto &it:dp[node])
      {
          if(it!=p)
          {
              find(it,val,node);
              val[node][0]+=val[it][1];
              val[node][1]+=min(val[it][1],val[it][0]);
          }
      }
    //   for(auto &it:dp[node])
    //   {
    //       if(it!=p)
    //       {
    //           val[node][0]+=val[it][1];
    //           val[node][1]+=min(val[it][1],val[it][0]);
    //       }
    //   }
  }
    int countVertex(int n, vector<vector<int>>edges)
    {
        dp=vector<vector<int>>(n+1);
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<vector<int>>val(n+1);
        for(int i=1;i<=n;i++)
        {
            val[i]={0,1};
        }
        find(1,val);
        return min(val[1][0],val[1][1]);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends