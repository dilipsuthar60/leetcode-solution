//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int count=0;
        int len=0;
        for(int i=0,j=0;i<n;i++)
        {
            if(arr[i]=='O')
            {
                count++;
            }
            while(count>m)
            {
                if(arr[j]=='O')
                {
                    count--;
                }
                j++;
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends