class Solution {
public:
    int mod=1e9+7;
    long long dp[51][101][51];
    int find(int n,int m,int k,int index,int prev_max,int prev_cost)
    {
        if(index==n)
        {
            return prev_cost==k;
        }
        if(dp[index][prev_max][prev_cost]!=-1)
        {
            return dp[index][prev_max][prev_cost]%mod;
        }
        long long  ans=0;
        for(int i=1;i<=m;i++)
        {
            int new_cost=prev_cost;
            int max_element=prev_max;
            if(i>max_element)
            {
                max_element=i;
                new_cost++;
            }
            ans=(ans+find(n,m,k,index+1,max_element,new_cost))%mod;
        }
        return dp[index][prev_max][prev_cost]= ans%mod;
    }
    int numOfArrays(int n, int m, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return find(n,m,k,0,0,0)%mod;
    }
};