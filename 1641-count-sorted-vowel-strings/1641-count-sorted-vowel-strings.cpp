class Solution {
public:
    int countVowelStrings(int n) 
    {
        int dp[5];
        for(int i=0;i<5;i++)
        {
            dp[i]=1;
        }
        while(--n)
        {
            for(int i=3;i>=0;i--)
            {
                dp[i]+=dp[i+1];
            }
        }
        int count=0;
        for(int i=0;i<5;i++)
        {
            count+=dp[i];
        }
        return count;
    }
};