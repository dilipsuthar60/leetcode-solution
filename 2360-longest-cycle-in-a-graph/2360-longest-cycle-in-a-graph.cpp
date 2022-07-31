class Solution {
public:
    int yes;
    int n;
    vector<int>dp[100005];
    vector<int>depth;
    int ans;
    void find(int x,int d)
    {
        if(depth[x]>0)
        {
            yes=1;
            ans=max(ans,d-depth[x]);
            return ;
        }
        if(depth[x]!=-1)
        {
            return ;
        }
        depth[x]=d;
        for(auto &it:dp[x])
        {
            find(it,d+1);
        }
        depth[x]=0;
    }
    int longestCycle(vector<int>&nums) 
    {
        yes=0;
        n=nums.size();
        depth=vector<int>(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=-1)
            {
                dp[i].push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(depth[i]==-1)
            {
                find(i,1);
            }
        }
        if(yes)
        {
            return ans;
        }
        return -1;
    }
};