class Solution {
public:
    int mod=1e9+7;
    long long dp[5001][7][16];
    int find(vector<int>&nums,int n,int index,int prev,int count)
    {
        if(index==n)
        {
            return 1;
        }
        if(dp[index][prev][count]!=-1)
        {
            return dp[index][prev][count]%mod;
        }
        long long  ans=0;
        for(int i=1;i<=6;i++)
        {
            if(i==prev&&count==nums[i-1])
            {
                continue;
            }
            int new_count=count;
            if(i==prev)
            {
                new_count++;
            }
            else
            {
                new_count=1;
            }
            ans+=find(nums,n,index+1,i,new_count);
        }
        return dp[index][prev][count]= ans%mod;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof(dp));
        return find(rollMax,n,0,0,0)%mod;
    }
};