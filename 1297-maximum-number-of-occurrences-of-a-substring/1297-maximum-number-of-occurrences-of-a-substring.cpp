class Solution {
public:
    int maxFreq(string s, int ml, int mn, int mx)
    {
        int count=0;
        int n=s.size();
        unordered_map<char,int>mp;
        unordered_map<string,int>freq;
        for(int i=0;i<mn;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]==1)
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
            mp[s[i]]++;
            if(mp[s[i]]==1)
            {
                count++;
            }
            if(mp[s[i-mn]]==1)
            {
                count--;
                mp.erase(s[i-mn]);
            }
            else
            {
                mp[s[i-mn]]--;
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