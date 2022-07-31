class Solution {
public:
    int yes;
    int n;
    vector<int>dp[100005];
    vector<int>depth;
    int vis[100005];
    int ans;
    void find(int x,int d)
    {
        depth[x]=d;
        vis[x]=1;
        for(auto &it:dp[x])
        {
            if(vis[it]==0)
            {
                find(it,d+1);
            }
            else if(vis[it]==1)
            {
                yes=1;
                ans=max(ans,depth[x]-depth[it]+1);
            }
        }
        vis[x]=2;
        // if(depth[x]>0)
        // {
        //     yes=1;
        //     ans=max(ans,d-depth[x]);
        //     return ;
        // }
        // if(depth[x]!=-1)
        // {
        //     return ;
        // }
        // depth[x]=d;
        // for(auto &it:dp[x])
        // {
        //     find(it,d+1);
        // }
        // depth[x]=0;
    }
    int longestCycle(vector<int>&nums) 
    {
        yes=0;
        n=nums.size();
        depth=vector<int>(n+1,-1);
        memset(vis,0,sizeof(vis));
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
        if(yes)
        {
            return ans;
        }
        return -1;
    }
};