//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int find(vector<int>&nums)
        {
             int len=0;
        int n=nums.size();
        vector<int>pos(nums.size()+1,0),neg(nums.size()+1,0);
        for(int i=1;i<=n;i++)
        {
            if(nums[i-1]>0)
            {
                pos[i]=pos[i-1]+1;
                neg[i]=neg[i-1];
            }
            if(nums[i-1]<0)
            {
                pos[i]=pos[i-1];
                neg[i]=neg[i-1]+1;
            }
            if(neg[i]%2==0)
            {
                len=max(len,neg[i]+pos[i]);
            }
        }
        return len;
            // int ans=0;
            // int n=nums.size();
            // vector<int>pos(n,0),neg(n,0);
            // for(int i=0;i<n;i++)
            // {
            //     if(nums[i]>0)
            //     {
            //         pos[i]=(i-1>=0)?pos[i-1]+1:0;
            //         neg[i]=(i-1>=0)?neg[i-1]:0;
            //     }
            //     if(nums[i]<0)
            //     {
            //         pos[i]=(i-1>=0)?pos[i-1]:0;
            //         neg[i]=(i-1>=0)?neg[i-1]+1:0;
            //     }
            //     if(neg[i]%2==0)
            //     {
            //         ans=max(ans,pos[i]+neg[i]);
            //     }
            // }
            // return ans;
        }
        int maxLength(vector<int> &arr,int n){
           //code here
           vector<int>arr1=arr;
           reverse(arr1.begin(),arr1.end());
           return max(find(arr),find(arr1));
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends