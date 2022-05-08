class Solution {
public:
    int mod=1e9+7;
    int dp[100005];
    int find(string &s,int index)
    {
        if(index>=s.size())
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        long long ans=0;
        ans+=find(s,index+1);
        if((index+1<s.size())&&s[index]==s[index+1])
        {
            ans+=find(s,index+2);
            if(index+2<s.size()&&s[index]==s[index+2])
            {
                ans+=find(s,index+3);
                if(index+3<s.size()&&s[index]==s[index+3]&&(s[index]=='7'||s[index]=='9'))
                {
                    ans+=find(s,index+4);
                }
            }
        }
        return dp[index]=ans%mod;
    }
    int countTexts(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return find(s,0);
    }
};