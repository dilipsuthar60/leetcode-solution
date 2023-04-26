//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    vector<int>v;
    int dp[10004][4];
    int find(int n,int index)
    {
        if(n<0)
        {
            return -1e9;
        }
        if(index>=3)
        {
            return n==0?0:-1e9;
        }
        if(dp[n][index]!=-1)
        {
            return dp[n][index];
        }
        int ans=find(n,index+1);
        for(auto it:v)
        {
            ans=max(ans,1+find(n-it,index));
        }
        return dp[n][index]= ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
 
        v={x,y,z};
        return max(find(n,0),0);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends