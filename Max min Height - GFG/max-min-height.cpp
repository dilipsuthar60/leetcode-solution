//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    bool find(vector<int>&nums,int k,int w,int n,long long mid)
    {
        long long ans=0;
        vector<long long>dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                dp[i]+=dp[i-1];
            }
            if(nums[i]+dp[i]<mid)
            {
                long long need=mid-(nums[i]+dp[i]);
                dp[i]+=need;
                 ans+=need;
                if(i+w<n)
                {
                    dp[i+w]-=need;
                }
            }
        }
        return ans<=k;
    }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            long long ans=0;
            long long l=0;
            long long r=1e14;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if(find(a,k,w,n,mid))
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends