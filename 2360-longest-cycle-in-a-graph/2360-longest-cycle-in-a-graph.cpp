class Solution {
public:
    int yes;
    int n;
    vector<vector<int>>dp;
    vector<int>depth;
    vector<int>vis;
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
    }
    int longestCycle(vector<int>&nums) 
    {
        yes=0;
        n=nums.size();
        dp=vector<vector<int>>(n+1);
        depth=vector<int>(n+1,-1);
        vis=vector<int>(n+1);
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