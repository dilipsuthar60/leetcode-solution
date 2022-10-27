class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>dp[2];
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1.size();j++)
            {
                if(img1[i][j])
                {
                    dp[0].push_back({i,j});
                }
            }
        }
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1.size();j++)
            {
                if(img2[i][j])
                {
                    dp[1].push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>mp;
        int ans=0;
        for(int i=0;i<dp[0].size();i++)
        {
            for(int j=0;j<dp[1].size();j++)
            {
                mp[{dp[0][i].first-dp[1][j].first,dp[0][i].second-dp[1][j].second}]++;
            }
        }
        for(auto&[a,b]:mp)
        {
            ans=max(ans,b);
        }
        return ans;
    }
};