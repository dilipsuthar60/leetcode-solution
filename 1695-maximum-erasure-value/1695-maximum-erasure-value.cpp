class Solution {
public:
    int dp[100009];
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int ans=0;
        int sum=0;
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n&&j<n)
        {
            if(dp[nums[i]]==0)
            {
                sum=sum+nums[i];
                ans=max(ans,sum);
                dp[nums[i]]=1;
                i++;
            }
            else
            {
                sum=sum-nums[j];
                dp[nums[j++]]=0;
            }
        }
        return ans;
    }
};