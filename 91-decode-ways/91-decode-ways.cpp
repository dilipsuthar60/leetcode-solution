class Solution {
public:
    int n;
    int dp[101];
    int find(string &s,int index)
    {
        if(index>=n)
        {
            return 1;
        }
        if(s[index]=='0')
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=find(s,index+1);
        if(index+1<n)
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
        n=s.size();
        memset(dp,-1,sizeof(dp));
        return find(s,0);
    }
};