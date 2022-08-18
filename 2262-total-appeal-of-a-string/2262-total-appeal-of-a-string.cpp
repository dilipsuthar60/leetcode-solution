class Solution {
public:
    long long find(string &s,int k)
    {
        long long  count=0;
        long long dp[26];
        memset(dp,0,sizeof(dp));
        int n=s.size();
        int unique=0;
        for(int i=0,j=0;i<n;i++)
        {
            if(dp[s[i]-'a']==0)
            {
                unique++;
            }
             dp[s[i]-'a']++;
            while(unique>k)
            {
                 dp[s[j]-'a']--;
                if(dp[s[j]-'a']==0)
                {
                    unique--;
                }
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
    long long appealSum(string s) 
    {
        int n=s.size();
        long long count=0;
        vector<int>dp(26,-1);
        for(int i=0;i<n;i++)
        {
            long long sum=(n-i)*(i-dp[s[i]-'a']);
            count+=sum;
            dp[s[i]-'a']=i;
        }
        return count;
        // for(int i=1;i<=26;i++)
        // {
        //     long long x=find(s,i)-find(s,i-1);
        //     count+=(1ll*x*i);
        // }
        // return count;
    }
};