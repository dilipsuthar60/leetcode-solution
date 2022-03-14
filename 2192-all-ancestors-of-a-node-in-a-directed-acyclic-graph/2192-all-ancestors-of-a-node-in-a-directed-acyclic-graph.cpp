class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& nums) 
    {
        vector<vector<int>>dp(n);
        for(auto &it:nums)
        {
            dp[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++)
        {
            queue<int>q;
            vector<bool>vis(n,false);
            q.push(i);
            vis[i]=true;
            for(;q.size();q.pop())
            {
                auto temp=q.front();
                for(auto child:dp[temp])
                {
                    if(vis[child]==false)
                    {
                        vis[child]=true;
                        q.push(child);
                        ans[child].push_back(i);
                    }
                }
            }
        }
        return ans;
    }
};