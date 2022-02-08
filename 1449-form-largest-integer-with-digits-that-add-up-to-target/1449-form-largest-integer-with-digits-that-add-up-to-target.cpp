class Solution {
public:
    string largestNumber(vector<int>& cost, int target)
    {
       
        vector<int>dp(target+1,0);
        dp[0]=0;
        for(int i=1;i<=target;i++)
        {
            dp[i]=INT_MIN;
            for(int j=0;j<cost.size();j++)
            {
                if(i-cost[j]>=0)
                {
                    dp[i]=max(dp[i],1+dp[i-cost[j]]);
                }
            }
        }
        if(dp[target]<0)
        {
            return "0";
        }
        string s="";
        for(int i=8;~i;i--)
        {
            while(target>=cost[i]&&dp[target]==dp[target-cost[i]]+1)
            {
                s.push_back(i+1+'0');
                target-=cost[i];
            }
        }
        return s;
    }
};