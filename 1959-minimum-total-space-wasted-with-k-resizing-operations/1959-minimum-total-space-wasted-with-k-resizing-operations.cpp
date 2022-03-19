class Solution {
public:
    int dp[210][210];
    int find(vector<int>&nums,int index,int k)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(k==-1)
        {
            return INT_MAX/2;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        int sum=0;
        int ans=INT_MAX/2,max_element=nums[index];
        for(int i=index;i<nums.size();i++)
        {
            sum+=nums[i];
            max_element=max(max_element,nums[i]);
            ans=min(ans,max_element*(i-index+1)-sum+find(nums,i+1,k-1));
        }
        return dp[index][k]=ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,k);
    }
};