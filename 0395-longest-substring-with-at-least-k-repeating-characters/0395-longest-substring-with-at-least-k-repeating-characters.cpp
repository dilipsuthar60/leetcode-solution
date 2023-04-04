class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n=s.size();
        int ans=0;
        for(int unique=1;unique<=26;unique++)
        {
            int dp[26]={0};
            int countu=0;
            int countk=0;
            for(int i=0,j=0;i<n;i++)
            {
                if(dp[s[i]-'a']++==0)
                {
                    countu++;
                }
                if(dp[s[i]-'a']==k)
                {
                    countk++;
                }
                while(countu>unique)
                {
                    dp[s[j]-'a']--;
                    if(dp[s[j]-'a']==0)
                    {
                        countu--;
                    }
                    if(dp[s[j]-'a']==k-1)
                    {
                        countk--;
                    }
                    j++;
                }
                if(unique==countu&&unique==countk)
                {
                    ans=max(ans,i-j+1);
                }
            }
        }
        return ans;
    }
};