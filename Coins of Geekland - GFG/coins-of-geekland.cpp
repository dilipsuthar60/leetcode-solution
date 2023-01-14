//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int q(vector<vector<int>>&dp,int x2,int y2,int x1,int y1)
    {
        return dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]; 
    }
    int Maximum_Sum(vector<vector<int>> &mat,int N,int k)
    {
        int n=N;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=mat[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        int ans=-1e9;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
    
                if(i+k-1<=n&&j+k-1<=n)
                {
                    ans=max(ans,q(dp,i+k-1,j+k-1,i,j));
                }
            }
            // cout<<endl;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}

// } Driver Code Ends