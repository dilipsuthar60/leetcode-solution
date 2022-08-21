class Solution {
public:
    string largestPalindromic(string s) 
    {
        int n=s.size();
        int dp[10];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[s[i]-'0']++;
        }
        int len=0;
        for(int i=0;i<=9;i++)
        {
            len+=(dp[i]/2)*2;
        }
        // int r=len-1;
        // int l=0;
        string ans;
        // ans=string(len,'0');
        for(int i=9;i>=0;i--)
        {
            if(ans.size()==0&&i==0)
            {
                continue;
            }
            while(dp[i]!=0&&dp[i]>=2)
            {
                ans.push_back(i+'0');
                dp[i]-=2;
            }
        }
        int mid_val=-1;
        for(int i=0;i<=9;i++)
        {
            if(dp[i])
            {
                mid_val=max(mid_val,i);
            }
        }
        int f=0;
        // while(ans.size()&&ans.back()=='0')
        // {
        //     f=1;
        //     ans.pop_back();
        // }
        // if(f&&ans.size()==0&&mid_val==-1)
        // {
        //     return "0";
        // }
        string str1=ans;
        string str2=ans;
        reverse(str2.begin(),str2.end());
        return str1+(mid_val!=-1?string(1,mid_val+'0'):"")+str2;
    }
};