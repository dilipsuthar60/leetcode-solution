class Solution {
public:
    vector<vector<int>>dp;
    void find(int x,int p,vector<vector<int>>&ans,vector<bool>&vis)
    {
        vis[x]=true;
        for(auto it:dp[x])
        {
            if(vis[it]==false)
            {
                ans[it].push_back(p);
                find(it,p,ans,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>&nums) 
    {
        dp.resize(n+1);
        for(auto &it:nums)
        {
            dp[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            vector<bool>vis(n,false);
            find(i,i,ans,vis);
        }
        return ans;
    }
};