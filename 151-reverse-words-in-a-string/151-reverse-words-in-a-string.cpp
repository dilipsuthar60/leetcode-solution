class Solution {
public:
    string reverseWords(string s) 
    {
        int n=s.size();
        string ans="";
        reverse(s.begin(),s.end());
        string take="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                take+=s[i];
            }
            else if(take.size())
            {
                reverse(take.begin(),take.end());
                ans+=take+" ";
                take="";
            }
        }
        reverse(take.begin(),take.end());
        ans+=take;
        if(ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};