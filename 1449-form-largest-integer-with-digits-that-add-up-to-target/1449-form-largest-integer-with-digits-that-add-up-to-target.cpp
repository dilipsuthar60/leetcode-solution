class Solution {
public:
    string largestNumber(vector<int>& cost, int target) 
    {
        int n=cost.size();
        string dp[target+1];
        for(int i=0;i<=target;i++)
        {
            dp[i]="0";
        }
        dp[0]="";
        auto MAX=[&](string &s1,string&s2)
        {
            if(s1.size()==s2.size())
            {
                return max(s1,s2);
            }
            if(s1.size()>s2.size())
            {
                return s1;
            }
            return s2;
        };
        for(int i=0;i<n;i++)
        {
            for(int t=1;t<=target;t++)
            {
                if(t-cost[i]>=0&&dp[t-cost[i]]!="0")
                {
                   string s=to_string(i+1)+dp[t-cost[i]];
                   dp[t]=MAX(s,dp[t]);
                }
            }
        }
        return dp[target];
    }
};