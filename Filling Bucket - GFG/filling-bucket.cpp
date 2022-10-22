//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e8;
  long long dp[100005];
  long long find(int n)
  {
      if(n==0)
      {
          return 1;
      }
      if(n<0)
      {
          return 0;
      }
      if(dp[n]!=-1)
      {
          return dp[n];
      }
      long long first= find(n-1);
      long long second=find(n-2);
      return dp[n]= (first+second)%mod;
  }
    int fillingBucket(int N) {
        // code here
        memset(dp,-1,sizeof(dp));
        return find(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends