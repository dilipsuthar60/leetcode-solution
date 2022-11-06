//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
         vector<int>coins{ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };

        vector<int>dp(N+1,1e8),parent(N+1,-1);
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0)
                {
                    parent[i]=j;
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        vector<int>ans;
        int i=N;
        while(N>0)
        {
            if(parent[i]!=-1)
            {
                ans.push_back(coins[parent[i]]);
            }
            N-=coins[parent[i]];
            i=N;
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends