//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    int find(int val,int arr[],int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if((arr[i]&val)==val)
            {
                count++;
            }
        }
        return count;
    }
    int maxAND (int arr[], int n)
    {
        int ans=0;
        for(int i=(int)log2(1000000);i>=0;i--)
        {
            int count=find(ans|(1<<i),arr,n);
            if(count>=2)
            {
                ans|=(1<<i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends