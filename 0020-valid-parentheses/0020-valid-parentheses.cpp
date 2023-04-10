class Solution {
public:
    bool isValid(string s)
    {
        if(!s.size())
        {
            return true;
        }
        stack<char>st;
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.size())
                {
                    return false;
                }
                if(s[i]==')'&&st.top()=='(')
                {
                    st.pop();
                }
                else if(s[i]=='}'&&st.top()=='{')
                {
                    st.pop();
                }
                else if(s[i]==']'&&st.top()=='[')
                {
                    st.pop();
                }
                else 
                {
                    return false;
                }
            }
        }
        return st.size()==0?true:false;
    }
};