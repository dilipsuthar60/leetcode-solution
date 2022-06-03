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
        int index=lower_bound(dp.begin(),dp.end(),X)-dp.begin();
        while(X>0ll)
        {
            if(index<dp.size()&&X==dp[index])
            {
                return 1;
            }
            if(index==0&&X!=dp[index])
            {
                return 0;
            }
            if(X>=dp[index-1])
            {
                X-=dp[index-1];
            }
            index--;
        }
        if(X==0)
        {
            return 1;
        }
        return 0;
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