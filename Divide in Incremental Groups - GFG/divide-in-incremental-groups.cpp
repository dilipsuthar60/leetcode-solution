//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dp[110][110][110];
  int find(int N,int prev,int k)
  {
      if(N<0||k<0)
      {
          return 0;
      }
      if(N==0)
      {
          return k==0;
      }
      if(dp[prev+1][N][k]!=-1)
      {
          return dp[prev+1][N][k];
      }
      int ans=0;
      for(int i=1;i<=N;i++)
      {
          if(prev==-1||(N-i>=0&&prev<=i))
          {
              ans+=find(N-i,i,k-1);
          }
      }
      return dp[prev+1][N][k]=ans;
  }
    int countWaystoDivide(int N, int K) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return find(N,-1,K);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends