class Solution {
public:
    int n;
    long long memo[1004];
    long long find(vector<int>&nums,int index,int &k,vector<vector<int>>&dp)
    {
        if(index>=n)
        {
            return 0ll;
        }
        if(memo[index]!=-1)
        {
            return memo[index];
        }
        long long ans=1e18;
        for(int i=index;i<n;i++)
        {
            ans=min(ans,1ll*dp[index][i]+1ll*k+find(nums,i+1,k,dp));
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
            int f[1004];
            memset(mp,0,sizeof(mp));
            memset(f,0,sizeof(f));
            for(int j=i;j<n;j++)
            {
                int prev=mp[nums[j]];
                mp[nums[j]]++;
                if(mp[nums[j]]>=2)
                {
                    if(f[nums[j]]==1)
                    {
                    count+=(mp[nums[j]]-prev);
                    }
                    else
                    {
                        f[nums[j]]=1;
                        count+=(mp[nums[j]]);
                    }
                }
                dp[i][j]=count;
            }
        }
        return find(nums,0,k,dp);
    }
};