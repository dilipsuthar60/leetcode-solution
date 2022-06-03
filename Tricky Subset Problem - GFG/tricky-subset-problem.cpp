// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        vector<long long>dp;
        long long curr=S;
        long long sum=S;
        dp.push_back(S);
        for(int i=0;i<N;i++)
        {
            curr=sum+A[i];
            if(curr>X)
            {
                break;
            }
            dp.push_back(curr);
            sum=curr+sum;
        }
        for(int i=dp.size()-1;i>=0;i--)
        {
            if(X>=dp[i])
            {
                X-=dp[i];
            }
        }
        return X==0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends