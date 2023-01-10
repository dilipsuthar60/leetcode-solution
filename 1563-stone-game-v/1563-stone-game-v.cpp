class Solution {
public:
    int dp[501][501];
    int find(vector<int>&nums,int l,int r)
    {
        if(l>=r)
        {
            return 0;
        }
        int ans=0;
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        for(int p=l;p<r;p++)
        {
            int left_sum=nums[p]-((l==0)?0:nums[l-1]);
            int right_sum=nums[r]-nums[p];
            if(left_sum<right_sum)
            {
                ans=max(ans,left_sum+find(nums,l,p));
            }
            else if(left_sum>right_sum)
            {
                ans=max(ans,right_sum+find(nums,p+1,r));
            }
            else
            {
                ans=max({ans,left_sum+find(nums,l,p),right_sum+find(nums,p+1,r)});
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>&nums) 
    {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        return find(nums,0,n-1);
    }
};