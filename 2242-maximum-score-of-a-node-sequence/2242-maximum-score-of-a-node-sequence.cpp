class Solution {
public:
    int maximumScore(vector<int>& sc, vector<vector<int>>&nums)
    {    
        int n=sc.size();
        vector<int>dp[n+1];
        for(auto it:nums)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            sort(dp[i].begin(),dp[i].end(),[&](auto &a,auto &b)
                 {
                     return sc[a]>sc[b];
                 });
        }
        int ans=-1;
        for(auto it:nums)
        {
            int a=it[0];
            int b=it[1];
            if(dp[a].size()<2||dp[b].size()<2)
            {
                continue;
            }
            for(int x=0;x<3&&x<dp[a].size();x++)
            {
                for(int y=0;y<3&&y<dp[b].size();y++)
                {
                    set<int>unique={a,b,dp[a][x],dp[b][y]};
                    if(unique.size()==4)
                    {
                        ans=max(ans,sc[a]+sc[b]+sc[dp[a][x]]+sc[dp[b][y]]);
                    }
                }
            }
        }
        return ans;
    }
};