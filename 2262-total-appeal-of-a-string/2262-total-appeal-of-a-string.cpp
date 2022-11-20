class Solution {
public:
    long long appealSum(string s) 
    {
        int n=s.size();
        unordered_map<char,int>dp;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int val=-1;
            if(dp.count(s[i]))
            {
                val=dp[s[i]];
            }
            ans+=1ll*(n-i)*(i-val);
            dp[s[i]]=i;
        }
        return ans;
    }
};