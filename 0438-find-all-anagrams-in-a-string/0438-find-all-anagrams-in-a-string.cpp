class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(s.size()<p.size())
        {
            return {};
        }
        vector<int>dp1(26,0),dp2(26,0);
        for(int i=0;i<p.size();i++)
        {
            dp1[p[i]-97]++;
            dp2[s[i]-97]++;
        }
        vector<int>ans;
        if(dp1==dp2)
        {
            ans.push_back(0);
        }
        for(int i=p.size();i<s.size();i++)
        {
            dp2[s[i-(int)p.size()]-97]--;
            dp2[s[i]-97]++;
            if(dp1==dp2)
            {
                ans.push_back(i-p.size()+1);
            }
        }
        return ans;
    }
};