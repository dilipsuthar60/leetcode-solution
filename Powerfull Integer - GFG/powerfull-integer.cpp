//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
       map<int,int>mp;
       for(auto it:intervals)
       {
           mp[it[0]]=0;
           mp[it[1]]=0;
       }
       for(auto it:intervals)
       {
           mp[it[0]]++;
           mp[it[1]+1]--;
       }
       int ans=-1;
       int sum=0;
       for(auto &it:mp)
       {
           sum+=it.second;
           if(sum>=k)
           {
               ans=max(ans,it.first);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends