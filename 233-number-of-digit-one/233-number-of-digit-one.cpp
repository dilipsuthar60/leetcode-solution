class Solution {
public:
    string s;
    int dp[10][2][10];
    int find(int n,int pos=0,int tight=1,int count=0)
    {
        if(pos==n)
        {
            return count;
        }
        if(dp[pos][tight][count]!=-1)
        {
            return dp[pos][tight][count];
        }
        int ans=0;
        if(tight==1)
        {
            for(int i=0;i<=s[pos]-'0';i++)
            {
                int new_tight=0;
                int new_count=count;
                if(i==s[pos]-'0')
                {
                    new_tight=1;
                }
                if(i==1)
                {
                    new_count++;
                }
                ans+=find(n,pos+1,new_tight,new_count);
            }
        }
        else
        {
            for(int i=0;i<=9;i++)
            {
                int new_count=count;
                if(i==1)
                {
                    new_count++;
                }
                ans+=find(n,pos+1,0,new_count);
            }
        }
        return dp[pos][tight][count]=ans;
    }
    int countDigitOne(int n) 
    {
        memset(dp,-1,sizeof(dp));
        s=to_string(n);
        return find(s.size());
    }
};