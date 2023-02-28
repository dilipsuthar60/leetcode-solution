//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
    
        vector<int>nums(n);
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                nums[i]=a[i];
                nums[i]+=nums[i-1];
            }
            else
            {
                nums[i]=a[i];
            }
        }
        vector<int>ans;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int mid=i/2;
            int left_sum=nums[mid];
            int total=(i+1);
            int right_sum=nums[i]-(nums[mid]);
            ans.push_back(abs((mid+1)*a[mid]-left_sum)+abs(right_sum-(i+1-mid-1)*a[mid]));
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends