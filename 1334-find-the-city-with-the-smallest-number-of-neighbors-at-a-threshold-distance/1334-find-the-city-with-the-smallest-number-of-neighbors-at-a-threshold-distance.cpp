class Solution {
public:
    int findTheCity(int n, vector<vector<int>>&mat, int val) 
    {
        vector<vector<int>>dp(n,vector<int>(n,1e5));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(auto &it:mat)
        {
            dp[it[0]][it[1]]=it[2];
            dp[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans=0;
        int max_val=n;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]<=val)
                {
                    count++;
                }
            }
            if(count<=max_val)
            {
                max_val=count;
                ans=i;
            }
        }
        return ans;
    }
};
// vector<vector<int>> dis(n, vector(n, 10001));
//         int res = 0, smallest = n;
//         for (auto& e : edges)
//             dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
//         for (int i = 0; i < n; ++i)
//             dis[i][i] = 0;
//         for (int k = 0; k < n; ++k)
//             for (int i = 0; i < n; ++i)
//                 for (int j = 0; j < n; ++j)
//                     dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//         for (int i = 0; i < n; i++) {
//             int count = 0;
//             for (int j = 0; j < n; ++j)
//                 if (dis[i][j] <= distanceThreshold)
//                     ++count;
//             if (count <= smallest) {
//                 res = i;
//                 smallest = count;
//             }
//         }
//         return res;