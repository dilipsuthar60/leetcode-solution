class Solution {
public:
    int n;
    int dp[1006];
    int find(vector<int>&nums,int index,int d)
    {
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=0;
        for(int i=index+1;i<n&&nums[i]<nums[index]&&i<=index+d;i++)
        {
            ans=max(ans,1+find(nums,i,d));
        }
        for(int i=index-1;i>=0&&nums[i]<nums[index]&&i>=index-d;i--)
        {
            ans=max(ans,1+find(nums,i,d));
        }
        return dp[index]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            ans=max(ans,1+find(arr,i,d));
        }
        return ans;
    }
};