class Solution {
public:
    int maxFreq(string s, int ml, int mn, int mx)
    {
        int count=0;
        int n=s.size();
        int dp[27];
        memset(dp,0,sizeof(dp));
        unordered_map<string,int>freq;
        string str="";
        for(int i=0;i<mn;i++)
        {
            if(++dp[s[i]-97]==1)
            {
                count++;
            }
            str+=s[i];
        }
        if(count<=ml)
        {
            freq[str]++;
        }
        for(int i=mn;i<n;i++)
        {
            str+=s[i];
            str.erase(str.begin());
            if(++dp[s[i]-97]==1)
            {
                count++;
            }
            if(--dp[s[i-mn]-97]==0)
            {
                count--;
            }
            if(count<=ml)
            {
                freq[str]++;
            }
        }
        int ans=0;
        for(auto&it:freq)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
};