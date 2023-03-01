//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
        vector<int> updateQuery(int n,int Q,vector<vector<int>> &q)
        {
            int dp[n][20];
            memset(dp,0,sizeof(dp));
            for(auto &it:q)
            {
                int l=it[0]-1;
                int r=it[1]-1;
                int x=it[2];
                for(int i=0;i<20;i++)
                {
                    if(x&(1<<i))
                    {
                      dp[l][i]++;
                      if(r+1<n)
                      dp[r+1][i]--;
                    }
                }
            }
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<20;j++)
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
            vector<int>ans(n);
            for(int i=0;i<n;i++)
            {
                int value=0;
                for(int j=0;j<20;j++)
                {
                    if(dp[i][j]>0)
                    {
                        value+=(1<<j);
                    }
                }
                ans[i]=value;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends