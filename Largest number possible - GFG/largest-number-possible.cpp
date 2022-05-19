// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sum)
    {
        if(n==1&&sum==0)
        {
            return "0";
        }
        if(n>1&&sum==0)
        {
            return "-1";
        }
        if(n*9<sum)
        {
            return "-1";
        }
        string s=string(n,'9');
        int A=n*9;
        for(int i=n-1;i>=0;i--)
        {
            int diff=max(-9,sum-A);
            s[i]+=diff;
            A+=diff;
        }
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends