class Solution {
public:
    int dp[10005];
    int find(string&s,int index)
    {
        if(index==s.size())
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        if(s[index]=='0')
        {
            return 0;
        }
        int ans=find(s,index+1);
        if(index+1<s.size())
        {
            int val=stoi(s.substr(index,2));
            if(val>=10&&val<=26)
            {
                ans+=find(s,index+2);
            }
        }
        return dp[index]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return find(s,0);
    }
};