class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int>dp[26];
        int n=s.size();
        for(int i=0;i<26;i++)
        {
            dp[i].push_back(-1);
        }
        for(int i=0;i<n;i++)
        {
            dp[s[i]-'A'].push_back(i);
        }
        for(int i=0;i<26;i++)
        {
            dp[i].push_back(n);
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=1;j<dp[i].size()-1;j++)
            {
                ans+=(dp[i][j]-dp[i][j-1])*(dp[i][j+1]-dp[i][j]);
            }
        }
        return ans;
    }
};