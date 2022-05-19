// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int dp[100005][2][3];
int find(vector<int>&nums,int index,int buy,int k)
{
    if(index>=nums.size()||k<=0)
    {
        return 0;
    }
    if(dp[index][buy][k]!=-1)
    {
        return dp[index][buy][k];
    }
    int ans=0;
    if(buy)
    {
        ans=max(-nums[index]+find(nums,index+1,0,k),find(nums,index+1,1,k));
    }
    else
    {
        ans=max(nums[index]+find(nums,index+1,1,k-1),find(nums,index+1,0,k));
    }
    return dp[index][buy][k]=ans;
}
int maxProfit(vector<int>&nums)
{
    memset(dp,-1,sizeof(dp));
    return find(nums,0,1,2);
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends