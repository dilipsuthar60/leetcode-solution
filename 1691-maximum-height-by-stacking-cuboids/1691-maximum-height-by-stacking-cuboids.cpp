class Solution {
public:
    int find(vector<vector<int>>&nums,int index,int prev)
    {
        return (nums[prev][0]<=nums[index][0]&&nums[prev][1]<=nums[index][1]&&nums[prev][2]<=nums[index][2]);
        // if(index==nums.size())
        // {
        //     return 0;
        // }
        // if(dp[index][prev+1]!=-1)
        // {
        //     return dp[index][prev+1];
        // }
        // int inc=0;
        // if(prev==-1||(nums[prev][0]<=nums[index][0]&&nums[prev][1]<=nums[index][1]&&nums[prev][2]<=nums[index][2]))
        // {
        //     inc=nums[index][2]+find(nums,index+1,index);
        // }
        // int exc=find(nums,index+1,prev);
        // return dp[index][prev+1]=max(inc,exc);
    }
    int maxHeight(vector<vector<int>>&nums)
    {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        int index=0;
        for(auto &it:nums)
        {
            sort(it.begin(),it.end());
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i][2];
            for(int j=0;j<i;j++)
            {
                if(find(nums,i,j)&&dp[j]+nums[i][2]>dp[i])
                {
                    dp[i]=dp[j]+nums[i][2];
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};