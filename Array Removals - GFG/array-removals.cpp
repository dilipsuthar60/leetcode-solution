//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[101][101];
    int find(vector<int>&nums,int i,int j,int k)
    {
        if(nums[j]-nums[i]<=k)
        {
            return 0;
        }
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]= min(1+find(nums,i+1,j,k),1+find(nums,i,j-1,k));
    }
    int removals(vector<int>& arr, int k)
    {
        memset(dp,-1,sizeof(dp));
        sort(arr.begin(),arr.end());
        return find(arr,0,arr.size()-1,k);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends