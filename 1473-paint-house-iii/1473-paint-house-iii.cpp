class Solution {
public:
    int n,m;
    vector<int>nums;
    vector<vector<int>>cost;
    int target;
    int yes;
    int dp[101][101][101];
    int find(int index,int prev,int group)
    {
        if(group>target)
        {
            return 1e8;
        }
        if(index==m)
        {
            if(group==target)
            {
                yes=1;
                return 0;
            }
            return 1e8;
        }
        if(dp[index][prev][group]!=-1)
        {
            return dp[index][prev][group];
        }
        int ans=1e8;
        if(nums[index]==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(prev!=i)
                {
                    ans=min(ans,cost[index][i-1]+find(index+1,i,group+1));
                }
                else
                {
                    ans=min(ans,cost[index][i-1]+find(index+1,i,group));
                }
            }
        }
        else
        {
            if(prev!=nums[index])
            {
                ans=min(ans,find(index+1,nums[index],group+1));
            }
            else
            {
                ans=min(ans,find(index+1,nums[index],group));
            }
        }
        return dp[index][prev][group]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& costs, int M, int N, int targets) 
    {
        memset(dp,-1,sizeof(dp));
        yes=0;
        target=targets;
        cost=costs;
        nums=houses;
        n=N;
        m=M;
        int val=find(0,31,0);
        if(yes)
        {
            return val;
        }
        return -1;
    }
};