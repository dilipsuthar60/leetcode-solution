class Solution {
public:
    int N=2e5+10;
    int maxTotalFruits(vector<vector<int>>&nums, int start, int k) 
    {
        int n=nums.size();
        vector<int>dp(N,0);
        // int dp[N];
        // memset(dp,0,sizeof(dp));
        start++;
        for(auto &it:nums)
        {
            dp[it[0]+1]=it[1];
        }
        for(int i=0;i<N;i++)
        {
            if(i)
            dp[i]+=dp[i-1];
        }
        int ans=0;
        for(int r=start;r<=min(N-1,start+k);r++)
        {
            int l=min(start,start-(k-2*(r-start)));
            l=max(1,l);
            ans=max(ans,dp[r]-dp[l-1]);
        }
        for(int l=start;l>=max(1,start-k);l--)
        {
            int r=max(start,start+(k-2*(start-l)));
            r=min(N-1,r);
            ans=max(ans,dp[r]-dp[l-1]);
        }
        return ans;
    }
};