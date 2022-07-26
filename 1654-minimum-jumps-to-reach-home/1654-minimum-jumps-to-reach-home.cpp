class Solution {
public:
    int vis[6005];
    int dp[6005][3];
    int yes;
    int find(int index,int a,int b,int x,int f)
    {
        // cout<<index<<" ";
          if(index==x)
        {
              yes=1;
            return 0;
        }
        if(index<0||index>6000||vis[index])
        {
            return 1e8;
        }
        if(dp[index][f]!=-1)
        {
            return dp[index][f];
        }
        dp[index][f]=1+find(index+a,a,b,x,1);
        if(f)
        {
            dp[index][f]=min(dp[index][f],1+find(index-b,a,b,x,0));
        }
        return dp[index][f];
    }
    int minimumJumps(vector<int>& nums, int a, int b, int x)
    {
        yes=0;
        memset(dp,-1,sizeof(dp));
        for(auto &it:nums)
        {
            vis[it]=1;
        }
        int val=find(0,a,b,x,1);
        if(yes)
        {
            return val;
        }
        return -1;
    }
};