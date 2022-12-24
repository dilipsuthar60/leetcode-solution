//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
int dp[301][301];
int find(vector<int>&nums,int i ,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int cost=-1e9;
    for(int index=i;index<=j;index++)
    {
        cost=max(cost,nums[i-1]*nums[index]*nums[j+1]+find(nums,i,index-1)+find(nums,index+1,j));
    }
    return dp[i][j] = cost;
}
    int maxCoins(int N, vector<int> &arr) 
    {
        memset(dp,-1,sizeof(dp));
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        return find(arr,1,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends