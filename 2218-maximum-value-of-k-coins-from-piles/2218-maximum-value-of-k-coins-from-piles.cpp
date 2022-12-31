class Solution {
public:
    int n;
    int dp[1001][2001];
    int find(vector<vector<int>>&nums,int index,int k)
    {
        if(k==0)
        {
            return 0;
        }
        if(index>=n)
        {
            return 0 ;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int sum=0;
        int ans=0;
        for(int i=0;i<nums[index].size();i++)
        {
            if((k-i-1)>=0)
            {
                sum+=nums[index][i];
                ans=max(ans,sum+find(nums,index+1,k-i-1));
            }
        }
        ans=max(ans,find(nums,index+1,k));
        return dp[index][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>&nums, int k) 
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return find(nums,0,k);
    }
};