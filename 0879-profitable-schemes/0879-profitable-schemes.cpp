class Solution {
public:
    int mod=1e9+7;
    long long dp[101][101][101];
    long long find(int n,int index,int minp,vector<int>&group,vector<int>&profit)
    {
        if(index>=group.size())
        {
            return minp==0;
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n][index][minp]!=-1)
        {
            return dp[n][index][minp]%mod;
        }
        long long ans=find(n,index+1,minp,group,profit);
        if(group[index]<=n)
        {
           ans+=find(n-group[index],index+1,max(0,minp-profit[index]),group,profit); 
        }
        return dp[n][index][minp]= ans%mod;
    }
    int profitableSchemes(int n, int minp, vector<int>& group, vector<int>& profit) 
    {
        memset(dp,-1,sizeof(dp));
        return find(n,0,minp,group,profit);
    }
};