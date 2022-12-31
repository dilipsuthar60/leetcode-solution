class Solution {
public:
    long long nums[1005];
    long long dp[1005];
    long long find(int index,int n,int change)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        long long ans=1e9;
        for(int i=1;i<=n;i++)
        {
            if(index+i<=n)
            ans=min(ans,change+nums[i]+find(index+i,n,change));
        }
        return dp[index]=ans;
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
        return (int)find(0,num,changeTime)-changeTime;
    }
};