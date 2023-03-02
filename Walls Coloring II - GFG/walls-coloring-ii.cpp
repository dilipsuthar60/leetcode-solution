//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    pair<int,int>find_min(vector<int>&nums)
    {
        int n=nums.size();
        int first=INT_MAX;
        int second=first;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<first)
            {
                second=first;
                first=nums[i];
            }
            else if(nums[i]<second)
            {
                second=nums[i];
            }
        }
        return {first,second};
    }
    int minCost(vector<vector<int>> &mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=mat[0][i];
        }
        for(int i=1;i<n;i++)
        {
            auto temp=find_min(dp[i-1]);
            int first=temp.first;
            int second=temp.second;
            for(int j=0;j<m;j++)
            {
                if(dp[i-1][j]==first)
                {
                    dp[i][j]+=mat[i][j]+second;
                }
                else
                {
                    dp[i][j]+=mat[i][j]+first;
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end())<=0?-1:*min_element(dp[n-1].begin(),dp[n-1].end());
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends