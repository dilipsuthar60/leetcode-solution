//  int ans=1e9,xo=0,time=0;
//     void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& nums, vector<int>& sub, vector<int>& in, vector<int>& out)
//     {
//         in[node]=time++;
//         sub[node]=nums[node];
//         for(auto child: adj[node])
//         {
//             if(child==par) continue;
//             dfs(child,node,adj,nums,sub,in,out);
//             sub[node]^=sub[child];
//         }
//         out[node]=time++;
//     }
    
//     int minimumScore(vector<int>& nums, vector<vector<int>>& edges)
//     {
//         int n=nums.size();
//         vector<vector<int>> adj(n);
//         for(int i=0;i<n;i++)
//         {
//             xo^=nums[i];
//         }
//         for(int i=0;i<n-1;i++)
//         {
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         vector<int> sub(n,0),in(n),out(n);
//         dfs(0,0,adj,nums,sub,in,out);
//         for(int i=1;i<n;i++)
//         {
//             for(int j=1;j<n;j++)
//             {
//                 if(i==j) continue;
//                 else if(in[i]<in[j] && out[i]>out[j])
//                 {
//                     int x=sub[j];
//                     int y=sub[i]^sub[j];
//                     int z=xo^sub[i];
//                     int mn=min(x,min(y,z)),mx=max(x,max(y,z));
//                     ans=min(ans,mx-mn);
//                 }
//                 else if(in[i]>in[j] && out[i]<out[j])
//                 {
//                     int x=sub[i];
//                     int y=sub[i]^sub[j];
//                     int z=xo^sub[j];
//                     int mn=min(x,min(y,z)),mx=max(x,max(y,z));
//                     ans=min(ans,mx-mn);
//                 }
//                 else 
//                 {
//                     int x=sub[i];
//                     int y=sub[j];
//                     int z=xo^sub[i]^sub[j];
//                     int mn=min(x,min(y,z)),mx=max(x,max(y,z));
//                     ans=min(ans,mx-mn);
//                 }
//             }
//         }
//         return ans;
class Solution {
public:
    int in[1001],out[1001];
    int sub[1001];
    int time=1;
    vector<int>dp[1001];
    void find(int node,vector<int>&nums,int p=-1)
    {
        in[node]=time++;
        sub[node]=nums[node];
        for(auto &it:dp[node])
        {
            if(it!=p)
            {
               find(it,nums,node);
               sub[node]^=sub[it];
            }
        }
        out[node]=time++;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        find(0,nums);
        int total=sub[0];
        int ans=1e9;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                int x=i;
                int y=j;
                if(in[x]<in[y]&&out[x]>out[y])
                {
                    int first=sub[y];
                    int second=sub[x]^sub[y];
                    int third=total^sub[x];
                    ans=min({ans,max({first,second,third})-min({first,second,third})});
                }
                else if(in[x]>in[y]&&out[x]<out[y])
                {
                     int first=sub[x];
                     int second=sub[y]^sub[x];
                     int third=total^sub[y];
                      ans=min({ans,max({first,second,third})-min({first,second,third})});
                }
                else
                {
                    int first=sub[x];
                    int second=sub[y];
                    int third=total^sub[x]^sub[y];
                    ans=min({ans,max({first,second,third})-min({first,second,third})});
                }
            }
        }
        return ans;
    }
};