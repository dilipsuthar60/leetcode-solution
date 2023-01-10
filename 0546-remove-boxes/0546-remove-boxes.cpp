class Solution {
public:
    int dp[101][101][101];
    int find(vector<int>&nums,int l,int r,int k)
    {
        if(l>r)
        {
            return 0;
        }
        int ol=l;
        int ok=k;
        if(dp[ol][r][ok]!=-1)
        {
            return dp[ol][r][ok];
        }
        while(l+1<=r&&nums[l]==nums[l+1])
        {
            l++;
            k++;
        }
        int ans=(k+1)*(k+1)+find(nums,l+1,r,0);
        
        for(int m=l+1;m<=r;m++)
        {
            if(nums[l]==nums[m])
            {
                ans=max(ans,find(nums,m,r,k+1)+find(nums,l+1,m-1,0));
            }
        }
        return dp[ol][r][ok]  = ans;
    }
    int removeBoxes(vector<int>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,nums.size()-1,0);
    }
};