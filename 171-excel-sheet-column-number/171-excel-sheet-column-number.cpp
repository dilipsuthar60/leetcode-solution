class Solution {
public:
    int titleToNumber(string s)
    {
        int ans=0;
        int x=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            ans=ans+(s[i]-'A'+1)*(pow(26,x));
            x++;
        }
        return ans;
    }
};