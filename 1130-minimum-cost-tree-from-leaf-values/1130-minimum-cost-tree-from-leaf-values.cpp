class Solution {
public:
    int n;
    int maximum[50][50],dp[50][50];
    int find(vector<int>&nums,int l,int r)
    {
        if(l>=r)
        {
            return 0;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int ans=1e9;
        for(int i=l;i<r;i++)
        {
            ans=min(ans,maximum[l][i]*maximum[i+1][r]+find(nums,l,i)+find(nums,i+1,r));
        }
        return dp[l][r]=ans;
    }
    int mctFromLeafValues(vector<int>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        for(int i=0;i<n;i++)
        {
            maximum[i][i]=nums[i];
            for(int j=i+1;j<n;j++)
            {
                maximum[i][j]=max(maximum[i][j-1],nums[j]);
            }
        }
        return find(nums,0,n-1);
    }
};