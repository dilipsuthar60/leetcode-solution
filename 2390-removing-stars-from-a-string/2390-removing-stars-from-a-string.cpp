class Solution {
public:
    string removeStars(string s)
    {
        string stack="";
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]=='*')
            {
               if(stack.size())
               {
                   stack.pop_back();
               }
            }
            else
            {
                stack.push_back(s[i]);
            }
        }
        return stack;
    }
};