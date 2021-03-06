class Solution {
public:
    int n;
    // int dp[501][501];
    // int find(vector<int>&nums,int index,int time)
    // {
    //     if(index>=n)
    //     {
    //         return 0;
    //     }
    //     if(dp[index][time]!=-1)
    //     {
    //         return dp[index][time];
    //     }
    //     int inc=nums[index]*(time+1)+find(nums,index+1,time+1);
    //     int exc=find(nums,index+1,time);
    //     return dp[index][time]=max(inc,exc);
    // }
    int maxSatisfaction(vector<int>&nums) 
    {
        // memset(dp,-1,sizeof(dp));
        n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int suffix=0;
        int curr=0;
        for(int i=n-1;i>=0;i--)
        {
            suffix+=nums[i];
            curr+=suffix;
            ans=max(ans,curr);
        }
        return ans;
    }
};