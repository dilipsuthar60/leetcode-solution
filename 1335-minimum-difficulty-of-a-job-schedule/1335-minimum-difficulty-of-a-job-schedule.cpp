class Solution {
public:
    int n;
    int yes=0;
    int dp[301][12];
    int find(vector<int>&nums,int index,int d)
    {
        if(index>=n)
        {
            return 1e9;
        }
        if(dp[index][d]!=-1)
        {
            return dp[index][d];
        }
        if(d==1)
        {
            yes=1;
            int val=0;
            for(int i=index;i<n;i++)
            {
                val=max(val,nums[i]);
            }
            return val;
        }
        int max_val=nums[index];
        int ans=1e9;
        for(int i=index;i<n;i++)
        {
            max_val=max(max_val,nums[i]);
            ans=min(ans,max_val+find(nums,i+1,d-1));
        }
        return dp[index][d]=ans;
    }
    int minDifficulty(vector<int>&nums, int d) 
    {
        memset(dp,-1,sizeof(dp));
        yes=0;
        n=nums.size();
        int val=find(nums,0,d);
        if(yes)
        {
            return val;
        }
        return -1;
    }
};