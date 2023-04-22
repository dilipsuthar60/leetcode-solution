//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        map<long long ,long long>mp{{-1,0}};
        for(auto&it:arr)
        {
            mp[it]+=it;
        }
        long long sum=0;
        for(auto &it:mp)
        {
            sum+=it.second;
            it.second=sum;
        }
        vector<long long>ans;
        for(int i=0;i<n;i++)
        {
            auto it=mp.lower_bound(arr[i]);
            ans.push_back(prev(it)->second);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends