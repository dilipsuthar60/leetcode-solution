class Solution {
public:
    string s;
    int dp[40][2][3];
    int find(int n,int pos=0,int tight=1,int prev=0)
    {
        if(pos==n)
        {
            return 1;
        }
        if(dp[pos][tight][prev]!=-1)
        {
            return dp[pos][tight][prev];
        }
        int ans=0;
        if(tight==1)
        {
            for(int i=0;i<=s[pos]-'0';i++)
            {
                int new_tight=0;
                if(i==s[pos]-'0')
                {
                    new_tight=1;
                }
                if(i==1 &&prev==1)
                    continue;
                  ans+=find(n,pos+1,new_tight,i);
            }
        }
        else
        {
            for(int i=0;i<=1;i++)
            {
                 if(i==1 &&prev==1)
                    continue;
                ans+=find(n,pos+1,0,i);
            }
        }
        return dp[pos][tight][prev]=ans;
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        while(n)
        {
            s.push_back(n%2+'0');
            n=n/2;
        }
        reverse(s.begin(),s.end());
        return find(s.size());
    }
};