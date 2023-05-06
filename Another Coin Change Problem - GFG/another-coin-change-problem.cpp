//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  vector<vector<int>>dp;
  int find(vector<int>&nums,int n,int k,int target)
  {
      if(k==0)
      {
          return target==0;
      }
      if(dp[k][target]!=-1)
      {
          return dp[k][target];
      }
      for(int i=0;i<n;i++)
      {
          if(target-nums[i]>=0&&find(nums,n,k-1,target-nums[i]))
          {
              return true;
          }
      }
      return dp[k][target]= false;
  }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        dp=vector<vector<int>>(K+1,vector<int>(target+1,-1));
        return find(coins,N,K,target);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends