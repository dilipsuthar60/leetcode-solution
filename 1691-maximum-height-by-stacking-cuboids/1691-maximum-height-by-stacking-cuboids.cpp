class Solution {
public:
   int dp[110][110];
    int find(vector<vector<int>>&nums,int index,int prev)
    {
        if(index==nums.size())
        {
            return 0;
        }
        if(dp[index][prev+1]!=-1)
        {
            return dp[index][prev+1];
        }
        int inc=0;
        if(prev==-1||(nums[prev][0]<=nums[index][0]&&nums[prev][1]<=nums[index][1]&&nums[prev][2]<=nums[index][2]))
        {
            inc=nums[index][2]+find(nums,index+1,index);
        }
        int exc=find(nums,index+1,prev);
        return dp[index][prev+1]=max(inc,exc);
    }
    int maxHeight(vector<vector<int>>&nums)
    {
        memset(dp,-1,sizeof(dp));
        for(auto &it:nums)
        {
            sort(it.begin(),it.end());
        }
        sort(nums.begin(),nums.end());
        return find(nums,0,-1);
    }
};