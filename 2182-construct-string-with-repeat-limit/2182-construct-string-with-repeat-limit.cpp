class Solution {
public:
    string repeatLimitedString(string s, int fr) 
    {   
        int n=s.size();
        vector<int>dp(26,0);
        for(int i=0;i<n;i++)
        {
            dp[s[i]-97]++;
        }
        string ans="";
        while(true)
        {
            int pos=-1;
            int one=0;
            for(int i=25;i>=0;i--)
            {
                if(ans.size()&&ans.back()==char(i+'a')&&dp[i])
                {
                    one=1;
                    continue;
                }
                if(dp[i])
                {
                    pos=i;
                    break;
                }
            }
            if(pos==-1)
            {
                break;
            }
            int val=one?1:min(fr,dp[pos]);
            dp[pos]-=val;
            ans+=string(val,pos+'a');
        }
        return ans;
    }
};