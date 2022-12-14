class Solution {
public:
    int find(vector<int>&nums,int index,vector<int>&dp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int robTakeThisPointGold=nums[index]+find(nums,index+2,dp);
        int robNotTakeThisPointGold=find(nums,index+1,dp);
        return dp[index] = max(robTakeThisPointGold,robNotTakeThisPointGold);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return find(nums,0,dp);
        // if(nums.size()==1)
        // {
        //     return nums[0];
        // }
        // int n=nums.size();
        // int prev2=nums[0];
        // int prev1=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     int temp=prev1;
        //     prev1=max(prev1,prev2+nums[i]);
        //     prev2=temp;
        // }
        // return prev1;
        // vector<int>dp(n+1,0);
        // dp[0]=nums[0];
        // dp[1]=max(nums[0],nums[1]);
        // for(int i=2;i<n;i++)
        // {
        //     dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        // }
        // return dp[n-1];
    }
};