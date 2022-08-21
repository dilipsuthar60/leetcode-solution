class Solution {
public:
    string shiftingLetters(string s, vector<int>& dp) 
    {
        int sum=0;
        int n=dp.size();
        for(int i=n-1;i>=0;i--)
        {
            sum=(sum+dp[i])%26;
            s[i]=(sum+s[i]-'a'+26)%26+'a';
        }
        return s;
    }
};