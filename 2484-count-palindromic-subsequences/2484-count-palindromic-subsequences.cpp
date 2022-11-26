class Solution {
public:
    int mod=1e9+7;
    long long dp[10004][11][11][6];
    int find(string &s,int index,int first,int second,int count)
    {
        if(count==5)
        {
            return 1;
        }
        if(index>=s.size())
        {
            return 0;
        }
        if(dp[index][first][second][count]!=-1)
        {
            return dp[index][first][second][count]%mod;
        }
        long long ans=find(s,index+1,first,second,count);
        if(count==0)
        {
            ans+=find(s,index+1,s[index]-'0',second,count+1);
        }
        else if(count==1)
        {
            ans+=find(s,index+1,first,s[index]-'0',count+1);
        }
        else if(count==2)
        {
            ans+=find(s,index+1,first,second,count+1);
        }
        else if(count==3)
        {
            if((s[index]-'0')==second)
            {
                ans+=find(s,index+1,first,second,count+1);
            }
        }
        else if(count==4)
        {
            if((s[index]-'0')==first)
            {
                ans+=find(s,index+1,first,second,count+1);
            }
        }
        return dp[index][first][second][count]= ans%mod;
        
    }
    int countPalindromes(string s) {
        memset(dp,-1,sizeof(dp));
        return find(s,0,10,10,0)%mod;
    }
};