class Solution {
public:
    int dp[1001];
    int find(vector<int>&nums,int index,int last)
    {
        if(index>=last)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        // if(index==nums.size()-1)
        // {
        //     return nums[index];
        // }
        return dp[index]=nums[index]+min(find(nums,index+1,last),find(nums,index+2,last));
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        memset(dp,-1,sizeof(dp));
        int n=cost.size();
        return min(find(cost,0,n),find(cost,1,n));
    }
};