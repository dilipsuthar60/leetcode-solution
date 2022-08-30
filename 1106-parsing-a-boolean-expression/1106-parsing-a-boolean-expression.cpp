class Solution {
public:
    int n;
    stack<char>st;
    void find()
    {
        bool hasf=false;
        bool hast=false;
        while(st.top()!='(')
        {
            auto temp=st.top();
            st.pop();
            if(temp=='f')
            {
                hasf=true;
            }
            else
            {
                hast=true;
            }
        }
        st.pop();
        char exp=st.top();
        st.pop();
        if(exp=='!')
        {
            if(hasf)
            {
                st.push('t');
            }
            else
            {
                st.push('f');
            }
        }
        if(exp=='&')
        {
            if(hasf&&hast)
            {
                st.push('f');
            }
            else if(hasf)
            {
                st.push('f');
            }
            else
            {
                st.push('t');
            }
        }
        if(exp=='|')
        {
              if(hasf&&hast)
            {
                st.push('t');
            }
            else if(hasf)
            {
                st.push('f');
            }
            else
            {
                st.push('t');
            }
        }
    }
    bool parseBoolExpr(string s) 
    {
        n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==',')
            {
                continue;
            }
            if(s[i]==')')
            {
                find();
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.top()=='t'?true:false;
    }
};