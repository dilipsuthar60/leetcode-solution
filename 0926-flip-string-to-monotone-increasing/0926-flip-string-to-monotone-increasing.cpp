class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
 int zero=count(s.begin(),s.end(),'0');
        int one=0;
        int ans=zero;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                one++;
            }
            else
            {
                zero--;
            }
            ans=min(ans,one+zero);
        }
        return ans;
    }
};