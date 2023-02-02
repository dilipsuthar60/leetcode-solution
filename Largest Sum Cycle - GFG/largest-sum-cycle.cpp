//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
    int yes;
    int n;
    vector<vector<long long>>dp;
    vector<long long>vis;
    long long ans;
    long long start=-1;
    long long end=-1;
    long long parent[100005];
    void find(int x,int d,int p=-1)
    {
        parent[x]=p;
        vis[x]=1;
        for(auto &it:dp[x])
        {
            if(vis[it]==0)
            {
             find(it,d+1,x);
            }
            else if(vis[it]==1)
            {
                start=it;
                end=x;
                int node=end;
                long long sum=0;
                while(start!=node)
                {
                 sum+=node;
                 node=parent[node];
                }
                sum+=node;
                ans=max(ans,sum);
            }
        }
        vis[x]=2; 
    }
  long long largestSumCycle(int N, vector<int> nums)
  {
       memset(parent,-1,sizeof(parent));
        yes=0;
        ans=-1;
        n=nums.size();
        dp=vector<vector<long long>>(n+1);
        vis=vector<long long>(n+1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                dp[i].push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                find(i,0);
            }
        }
        return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends