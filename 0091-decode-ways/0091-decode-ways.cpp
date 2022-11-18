class Solution {
public:
    int numDecodings(string s) 
    {
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=(s[0]=='0')?0:1;
        for(int i=2;i<=n;i++)
        {
            int val1=stoi(s.substr(i-1,1));
            int val2=stoi(s.substr(i-2,2));
            if(val1>=1&&val1<=9)
            {
                dp[i]+=dp[i-1];
            }
            if(val2>=10&&val2<=26)
            {
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};