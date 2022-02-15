class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) 
    {
        int n=days.size();
        vector<int>dp(370,0);
        for(auto it:days)
        {
            dp[it]=1;
        }
        auto valid=[&](int x,int i)
        {
            return max(0,i-x);
        };
        for(int i=1;i<=days[n-1];i++)
        {
            if(dp[i]==0)
            {
                dp[i]=dp[i-1];
            }
            else
            {
                dp[i]=dp[i-1]+cost[0];
                dp[i]=min(dp[i],dp[valid(7,i)]+cost[1]);
                dp[i]=min(dp[i],dp[valid(30,i)]+cost[2]);
            }
        }
        return dp[days[n-1]];
    }
};