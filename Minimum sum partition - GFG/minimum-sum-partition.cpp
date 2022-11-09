//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	vector<vector<int>>dp;
   bool find(int arr[],int index,int n,int target)
   {
    //   if(target==0)
    //   {
    //       return 1;
    //   }
       if(index==n)
       {
           return target==0;
       }
       if(target<0)
       {
           return 0;
       }
       if(dp[index][target]!=-1)
       {
           return dp[index][target];
       }
       return dp[index][target]= find(arr,index+1,n,target)||find(arr,index+1,n,target-arr[index]);
   }
	int minDifference(int arr[], int n)  
	{
	    int sum=accumulate(arr,arr+n,0);
	    int ans=sum;
	    dp=vector<vector<int>>(n+1,vector<int>(sum+1,-1));
	    for(int i=0;i<=sum;i++)
	    {
	        if(find(arr,0,n,i))
	        {
	            ans=min(ans,abs(sum-2*i));
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends