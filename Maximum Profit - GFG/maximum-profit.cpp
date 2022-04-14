// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int dp[501][201][3];
  int find(int nums[],int index,int k,int n,int buy)
  {
      if(index>=n||k==0)
      {
          return 0;
      }
      if(dp[index][k][buy]!=-1)
      {
          return dp[index][k][buy];
      }
      int ans=0;
      if(buy)
      {
          ans=max(-nums[index]+find(nums,index+1,k,n,0),find(nums,index+1,k,n,1));
      }
      else
      {
          ans=max(nums[index]+find(nums,index+1,k-1,n,1),find(nums,index+1,k,n,0));
      }
      return dp[index][k][buy]=ans;
  }
    int maxProfit(int K, int N, int A[]) {
        // code here
        memset(dp,-1,sizeof(dp));
        return find(A,0,K,N,1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends