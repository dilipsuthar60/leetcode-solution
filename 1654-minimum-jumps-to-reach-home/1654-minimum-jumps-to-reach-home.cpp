class Solution {
public:
    set<int>vis;
    int dp[9005][3];
    int yes;
    int find(int index,int a,int b,int x,int f)
    {
        // cout<<index<<" ";
          if(index==x)
        {
              yes=1;
            return 0;
        }
        if(index<0||index>6000||vis.find(index)!=vis.end())
        {
            return 1e9;
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
            vis.insert(it);
        }
        int val=find(0,a,b,x,1);
        if(yes)
        {
            return val;
        }
        return -1;
    }
};