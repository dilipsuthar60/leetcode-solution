class Solution {
public:
    int maxFreq(string s, int ml, int mn, int mx)
    {
        int count=0;
        int n=s.size();
        int dp[27];
        memset(dp,0,sizeof(dp));
        unordered_map<string,int>freq;
        for(int i=0;i<mn;i++)
        {
            if(++dp[s[i]-97]==1)
            {
                count++;
            }
        }
        if(count<=ml)
        {
            freq[s.substr(0,mn)]++;
        }
        for(int i=mn;i<n;i++)
        {
            if(++dp[s[i]-97]==1)
            {
                count++;
            }
            if(--dp[s[i-mn]-97]==0)
            {
                count--;
                // mp.erase(s[i-mn]);
            }
            if(count<=ml)
            {
                freq[s.substr(i-mn+1,mn)]++;
            }
        }
        int ans=0;
        for(auto&it:freq)
        {
            // cout<<it.first<<"  ";
            ans=max(ans,it.second);
        }
        return ans;
    }
};