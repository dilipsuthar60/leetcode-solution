class Solution {
public:
    int find(vector<vector<int>>&mat,int mid)
    {
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,1e9));
        dp[r][c-1]=dp[r-1][c]=1;
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                int need=min(dp[i+1][j],dp[i][j+1])-mat[i][j];
                if(need<=0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    dp[i][j]=need;
                }
            }
        }
        return dp[0][0];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        return find(dungeon,0);
        // int ans=0;
        // int l=1;
        // int r=1e9;
        // while(l<=r)
        // {
        //     int mid=(l+r)/2;
        //     if(find(dungeon,mid))
        //     {
        //         r=mid-1;
        //         ans=mid;
        //     }
        //     else
        //     {
        //         l=mid+1;
        //     }
        // }
        // return ans;
    }
};