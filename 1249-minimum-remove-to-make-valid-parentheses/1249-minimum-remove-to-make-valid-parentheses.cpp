class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int n=s.size();
        int open=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
                if(open==0)
                {
                    s[i]='@';
                    continue;
                }
                open--;
            }
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='('&&open>0)
            {
                s[i]='@';
                open--;
                continue;
            }
         
        }
        int p=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='@')
            {
                swap(s[p++],s[i]);
            }
        }
        return s.substr(0,p);
    }
};