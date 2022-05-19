// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> maxSumSequence(int n, int nums[])
    {
        int index=-1;
        int max_sum=INT_MIN;
        vector<int>dp(n,0),parent(n,-1);
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i];
            if(dp[i]>max_sum)
            {
                max_sum=dp[i];
                index=i;
            }
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&dp[i]<dp[j]+nums[i])
                {
                    dp[i]=dp[j]+nums[i];
                    parent[i]=j;
                    if(dp[i]>max_sum)
                    {
                        max_sum=dp[i];
                        index=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(index>=0)
        {
            ans.push_back(nums[index]);
            index=parent[index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        vector<int> ans = ob.maxSumSequence(N, A);
        for(auto num: ans)
            cout<<num<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends