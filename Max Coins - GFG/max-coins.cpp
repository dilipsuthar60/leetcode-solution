//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<vector<int>>dp;
int find_index(vector<vector<int>>&nums,int l,int end)
{
    int r=nums.size()-1;
    int index=nums.size();
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(end<=nums[mid][0])
        {
            index=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return index;
}
int find(vector<vector<int>>&nums,int index,int count)
{
    if(index>=nums.size()||count>=2)
    {
        return 0;
    }
    if(dp[index][count]!=-1)
    {
        return dp[index][count];
    }
    int not_take=find(nums,index+1,count);
    int new_index=find_index(nums,index+1,nums[index][1]);
    int take=nums[index][2]+find(nums,new_index,count+1);
    return dp[index][count]= max(not_take,take);
    
}
    int maxCoins(int n,vector<vector<int>> &nums){
        dp=vector<vector<int>>(nums.size()+1,vector<int>(3,-1));
        sort(nums.begin(),nums.end());
        return find(nums,0,0);
        // sort(nums.begin(),nums.end(),[&](auto&a,auto &b ){return a[1]<b[1];});
        // int ans=nums[0][2];
        // for(int i=1;i<n;i++)
        // {
        //     int start=nums[i][0];
        //     int end=nums[i][1];
        //     int cost=nums[i][2];
        //     nums[i][2]=max(nums[i][2],nums[i-1][2]);
        //     int l=0;
        //     int r=i-1;
        //     int index=-1;
        //     while(l<=r)
        //     {
        //         int mid=(l+r)/2;
        //         if(nums[mid][1]<start)
        //         {
        //             l=mid+1;
        //             index=mid;
        //         }
        //         else
        //         {
        //             r=mid-1;
        //         }
        //     }
        //     if(index!=-1)
        //     {
        //         cost+=nums[index][2];
        //     }
        //     ans=max(ans,cost);
        // }
        // return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends