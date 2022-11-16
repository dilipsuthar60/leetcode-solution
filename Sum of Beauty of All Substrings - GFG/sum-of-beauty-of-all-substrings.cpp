//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>dp(26,0);
            for(int j=i;j<n;j++)
            {
                dp[s[j]-'a']++;
                int first=INT_MIN;
                int second=INT_MAX;
                for(int k=0;k<26;k++)
                {
                    if(dp[k])
                    {
                        first=max(first,dp[k]);
                        second=min(second,dp[k]);
                    }
                }
                ans+=(first-second);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends