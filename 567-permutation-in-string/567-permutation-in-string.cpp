class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size()>s2.size())
        {
            return false;
        }
        vector<int>dp1(26,0),dp2(26,0);
        for(int i=0;i<s1.size();i++)
        {
            dp1[s1[i]-97]++;
            dp2[s2[i]-97]++;
        }
        if(dp1==dp2)
        {
            return true;
        }
        for(int i=s1.size();i<s2.size();i++)
        {
            dp2[s2[i-s1.size()]-97]--;
            dp2[s2[i]-97]++;
            if(dp1==dp2)
            {
                return true;
            }
        }
        return false;
    }
};