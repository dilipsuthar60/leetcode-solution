class Solution {
public:
    int n;
    int memo[1004];
    int find(vector<int>&nums,int index,int &k,vector<vector<int>>&dp)
    {
        if(index>=n)
        {
            return 0;
        }
        if(memo[index]!=-1)
        {
            return memo[index];
        }
        int ans=INT_MAX;
        for(int i=index;i<n;i++)
        {
            ans=min(ans,dp[index][i]+k+find(nums,i+1,k,dp));
        }
        return memo[index]= ans;
    }
    int minCost(vector<int>& nums, int k) {
        n=nums.size();
        memset(memo,-1,sizeof(memo));
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            int mp[1004];
            int count=0;
            memset(mp,0,sizeof(mp));
            for(int j=i;j<n;j++)
            {
                mp[nums[j]]++;
                if(mp[nums[j]]>=2)
                {
                    if(mp[nums[j]]==2)
                    {
                        count+=2;
                    }
                    else
                    {
                        count++;
                    }
                }
                dp[i][j]=count;
            }
        }
        return find(nums,0,k,dp);
    }
};