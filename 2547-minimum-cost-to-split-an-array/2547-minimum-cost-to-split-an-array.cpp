class Solution {
public:
    int n;
    int dp[1004];
    int find(vector<int>&nums,int index,int &k,vector<vector<int>>&range)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=INT_MAX;
        for(int i=index;i<n;i++)
        {
            ans=min(ans,range[index][i]+k+find(nums,i+1,k,range));
        }
        return dp[index]= ans;
    }
    int minCost(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>range(n,vector<int>(n,0));
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
                range[i][j]=count;
            }
        }
        return find(nums,0,k,range);
    }
};