//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        vector<vector<long long>>nums;
        for(int i=0;i<N;i++)
        {
            nums.push_back({r[i],g[i],b[i]});
        }
        vector<vector<long long>>dp(N+1,vector<long long>(3,0));
        for(int i=0;i<N;i++)
        {
            dp[i+1][0]=nums[i][0]+min(dp[i][1],dp[i][2]);
            dp[i+1][1]=nums[i][1]+min(dp[i][0],dp[i][2]);
            dp[i+1][2]=nums[i][2]+min(dp[i][0],dp[i][1]);
        }
        return min({dp[N][0],dp[N][1],dp[N][2]});
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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends