class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int dp[27][27];
        memset(dp,0,sizeof(dp));
        int len=0;
        for(auto it:words)
        {
            int first=it[0]-'a';
            int second=it[1]-'a';
            if(dp[second][first])
            {
                len+=4;
                dp[second][first]--;
            }
            else
            {
                dp[first][second]++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(dp[i][i])
            {
                len+=2;
                break;
            }
        }
        return len;
    }
};