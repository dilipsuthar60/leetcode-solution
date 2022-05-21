class Solution {
public:
    int find(string s,string t)
    {
        int n=s.size();
        int m=t.size();
        int dp1[256]={0};
        int dp2[256]={0};
        int j=0;
        for(int i=0;i<m;i++)
        {
            dp1[t[i]]++;
        }
        int len=INT_MAX;
        int count=0;
        for(int i=0;i<n;i++)
        {
            dp2[s[i]]++;
            if(dp1[s[i]]!=0&&dp2[s[i]]<=dp1[s[i]])
            {
                count++;
            }
            if(count==m)
            {
                while(j<=i&&((dp1[s[j]]==0)||dp2[s[j]]>dp1[s[j]]))
                {
                    dp2[s[j]]--;
                    j++;
                }
                int window=(i-j+1);
                len=min(len,window);
            }
        }
        return len;
    }
    int balancedString(string s) 
    {
        unordered_map<char,int>mp;
        for(auto &it:s)
        {
            mp[it]++;
        }
        int n=s.size();
        string t="";
        for(auto&[ch,f]:mp)
        {
            if(f>n/4)
            {
                t+=string(f-n/4,ch);
            }
        }
        return find(s,t);
    }
};