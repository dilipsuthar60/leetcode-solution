class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>dp(3,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            dp[s[i]-'a']++;
        }
        if(dp[0]<k||dp[1]<k||dp[2]<k)
        {
            return -1;
        }
        int len=0;
        for(int i=0,j=0;i<n;i++)
        {
            dp[s[i]-'a']--;
            while(dp[0]<k||dp[1]<k||dp[2]<k)
            {
                dp[s[j]-'a']++;
                j++;
            }
            len=max(len,i-j+1);
        }
        return n-len;
    }
};