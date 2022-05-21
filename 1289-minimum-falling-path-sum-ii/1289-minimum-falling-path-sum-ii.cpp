class Solution {
public:
    pair<int,int>find_min(vector<int>&nums)
    {
        int n=nums.size();
        int first=INT_MAX;
        int second=first;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<first)
            {
                second=first;
                first=nums[i];
            }
            else if(nums[i]<second)
            {
                second=nums[i];
            }
        }
        return {first,second};
    }
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=mat[0][i];
        }
        for(int i=1;i<n;i++)
        {
            auto [first,second]=find_min(dp[i-1]);
            for(int j=0;j<m;j++)
            {
                if(dp[i-1][j]==first)
                {
                    dp[i][j]+=mat[i][j]+second;
                }
                else
                {
                    dp[i][j]+=mat[i][j]+first;
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};