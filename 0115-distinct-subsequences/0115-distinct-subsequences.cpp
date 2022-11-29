class Solution {
public:
    int mod=1e9+7;
    int numDistinct(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=1;i<=n;i++)
        {
            prev[0]=1;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                   curr[j]=(prev[j-1]+prev[j])%mod;
                }
                else
                {
                    curr[j]=(prev[j])%mod;
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};