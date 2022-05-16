class Solution {
public:
    int n;
    int find(string &str,int a,int b)
    {
        int ans=0;
        string s=str;
        for(int round=0;round<2;round++)
        {
            int counta,countb;
            counta=countb=0;
            for(int i=0;i<n;i++)
            {
                counta+=(a==(s[i]-'a'));
                countb+=(b==(s[i]-'a'));
               // counta is higher
                if(counta&&countb)
                {
                    ans=max(ans,counta-countb);
                }
                if(countb>counta)
                {
                    counta=countb=0;
                }
            }
            reverse(s.begin(),s.end());
        }
        return ans;
    }
    int largestVariance(string s) 
    {
        int ans=0;
        n=s.size();
        int dp[26]={0};
        for(auto &it:s)
        {
            dp[it-97]++;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(dp[i]==0||dp[j]==0)
                {
                    continue;
                }
                ans=max(ans,find(s,i,j));
            }
        }
        return ans;
    }
};