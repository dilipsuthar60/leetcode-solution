class Solution {
public:
      int coinChange(vector<int>& coins, int x) 
    {
        vector<int>dp(x+1,x+1);
            dp[0]=0;
            for(int i=1;i<=x;i++)
            {
                for(int j=0;j<coins.size();j++)
                {
                    if(i-coins[j]>=0)
                    {
                        dp[i]=min(dp[i],dp[i-coins[j]]+1);
                    }
                }
            }
        if(dp[x]==x+1)
        {
            return -1;
        }
        return dp[x];
    }
    int minimumNumbers(int num, int k) 
    {
        vector<int>coin;
        for(int i=k;i<=num;i+=10)
        {
            coin.push_back(i);
        }
    
        return coinChange(coin,num);
    }
};