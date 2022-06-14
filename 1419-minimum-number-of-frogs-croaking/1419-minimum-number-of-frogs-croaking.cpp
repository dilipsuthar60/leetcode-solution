class Solution {
public:
    int minNumberOfFrogs(string s) 
    {
        int n=s.size();
        int f=0;
        int dp[128]={0};
        string str="croak";
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='c')
            {
                f++;
                ans=max(ans,f);
                dp['c']++;
            }
            else if(s[i]=='r')
            {
                if(dp['r']<dp['c'])
                {
                    dp['r']++;
                }
                else
                {
                    return -1;
                }
            }
            else if(s[i]=='o')
            {
                if(dp['o']<dp['r'])
                {
                    dp['o']++;
                }
                else
                {
                    return -1;
                }
            }
           else if(s[i]=='a')
           {
               if(dp['a']<dp['o'])
                {
                    dp['a']++;
                }
                else
                {
                    
                    return -1;
                }
           }
            else if(s[i]=='k')
            {
                if(dp['k']<dp['a'])
                {
                    dp['k']++;
                }
                else
                {
                    return -1;
                }
                f--;
            }
        }
        for(int i=0;i<str.size();i++)
        {
            if(dp[str[i]]!=dp['c'])
            {
                return -1;
            }
        }
        return ans;
    }
};