//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    vector<int>dp;
   int fun(int i,int arr[],int n){
        if(i>=n){
            return 0;
        }
        //int ma=INT_MIN;
        if(dp[i]!=-1){
            return dp[i];
        }
        int count=0;
        for(int j=i;j<n&&count<=3;j++){
            count++;
            dp[i]=max(dp[i],arr[j]+fun(j+2,arr,n));
        }
        return dp[i];
    }
    int FindMaxSum(int arr[], int n)
    {
        dp=vector<int>(n+1,-1);
        return fun(0,arr,n);
        // Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends