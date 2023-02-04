//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) 
	{
	    if(n==1)
	    {
	        return arr[0];
	    }
	    if(n==2)
	    {
	        return max(arr[1],arr[0]);
	    }
	   // vector<int>dp(n,0);
	    int prev2=arr[0];
	    int prev1=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++)
	    {
	        int temp=prev1;
	        prev1=max(prev2+arr[i],prev1);
	        prev2=temp;
	    }
	    return prev1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends