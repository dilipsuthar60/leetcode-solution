class Solution {
public:
    long long nums[1001];
    long long dp[1001];
    long long find(int n,int change)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        long long ans=1e9;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,change+nums[i]+find(n-i,change));
        }
        return dp[n]=ans;
    }
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int num) 
    {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<1001;i++)
        {
            nums[i]=1e18;
        }
        nums[0]=0;
        for(auto it:tires)
        {
            long long f=it[0];
            long long r=it[0];
            long long last=f;
            for(int i=1;i<=num;i++)
            {
                nums[i]=min(nums[i],last);
                r=r*it[1];
                if(r>1e8)
                {
                    break;
                }
                last+=r;
            }
        }
        return (int)find(num,changeTime)-changeTime;
    }
};