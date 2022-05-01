class Solution {
public:
    string find(string s)
    {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.size()&&s[i]=='#')
            {
                st.pop();
            }
            else if(s[i]!='#')
            {
                st.push(s[i]);
            }
        }
        s.clear();
        while(st.size())
        {
            s+=st.top();
            st.pop();
        }
        return s;
    }
    bool backspaceCompare(string s, string t) 
    {
        return find(s)==find(t);
    }
};