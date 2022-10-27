class Solution {
public:
    vector<vector<int>>dp;
    void find(int node,vector<int>&vis,int &maxCycle,vector<int>&depth,int d=0)
    {
        vis[node]=1;
        depth[node]=d;
        for(auto &it:dp[node])
        {
            if(vis[it]==0)
            {
                find(it,vis,maxCycle,depth,d+1);
            }
            else if(vis[it]==1)
            {
                // cout<<depth[it]<<"  "<<depth[node]<<endl;
                maxCycle=max(maxCycle,depth[node]-depth[it]+1);
            }
        }
        vis[node]=2;
    }
    int longestCycle(vector<int>&nums) 
    {
        int n=nums.size();
        dp=vector<vector<int>>(n+1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                dp[i].push_back(nums[i]);
            }
        }
        int maxCycle=-1;
        vector<int>vis(n+1,0),depth(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                find(i,vis,maxCycle,depth);
            }
        }
        return maxCycle;
    }
};
// class Solution {
// public:
//     int yes;
//     int n;
//     vector<vector<int>>dp;
//     vector<int>depth;
//     vector<int>vis;
//     int ans;
//     void find(int x,int d)
//     {
//         depth[x]=d;
//         vis[x]=1;
//         for(auto &it:dp[x])
//         {
//             if(vis[it]==0)
//             {
// 			//forward egde
//                 find(it,d+1);
//             }
//             else if(vis[it]==1)
//             {
// 			// back edge
//                 yes=1;
//                 ans=max(ans,depth[x]-depth[it]+1);
//             }
//         }
// 		// visited this path
//         vis[x]=2; 
//     }
//     int longestCycle(vector<int>&nums) 
//     {
//         yes=0;
//         n=nums.size();
//         dp=vector<vector<int>>(n+1);
//         depth=vector<int>(n+1,-1);
//         vis=vector<int>(n+1);
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]!=-1)
//             {
//                 dp[i].push_back(nums[i]);
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(vis[i]==0)
//             {
//                 find(i,0);
//             }
//         }
//         if(yes)
//         {
//             return ans;
//         }
//         return -1;
//     }
// };