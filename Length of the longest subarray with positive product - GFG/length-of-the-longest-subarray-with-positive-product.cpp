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
            int ans=0;
            int n=nums.size();
            int pos=0;
            int neg=0;
            // vector<int>pos(n,0),neg(n,0);
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    pos=0;
                    neg=0;
                }
                if(nums[i]>0)
                {
                    pos++;
                    // pos[i]=(i-1>=0)?pos[i-1]+1:1;
                    // neg[i]=(i-1>=0)?neg[i-1]:0;
                }
                if(nums[i]<0)
                {
                    neg++;
                    // pos[i]=(i-1>=0)?pos[i-1]:0;
                    // neg[i]=(i-1>=0)?neg[i-1]+1:1;
                }
                if(neg%2==0)
                {
                    ans=max(ans,pos+neg);
                }
            }
            return ans;
        }
        int maxLength(vector<int> &arr,int n)
        {
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