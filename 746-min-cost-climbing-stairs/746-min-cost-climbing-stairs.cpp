class Solution {
public:
    // int dp[1001];
    // int find(vector<int>&nums,int index,int last)
    // {
    //     if(index>=last)
    //     {
    //         return 0;
    //     }
    //     if(dp[index]!=-1)
    //     {
    //         return dp[index];
    //     }
    //     // if(index==nums.size()-1)
    //     // {
    //     //     return nums[index];
    //     // }
    //     return dp[index]=nums[index]+min(find(nums,index+1,last),find(nums,index+2,last));
    // }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        // memset(dp,-1,sizeof(dp));
        int n=cost.size();
        // return min(find(cost,0,n),find(cost,1,n));
        int dp[n];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};