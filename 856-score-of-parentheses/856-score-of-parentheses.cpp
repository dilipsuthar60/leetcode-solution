class Solution {
public:
    int scoreOfParentheses(string s)
    {
        int n=s.size();
        vector<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push_back(-1);
            }
            else
            {
                if(st.back()==-1)
                {
                    st.pop_back();
                    st.push_back(1);
                }
                else
                {
                    int val=0;
                    while(st.back()!=-1)
                    {
                        val+=st.back();
                        st.pop_back();
                    }
                    st.pop_back();
                    st.push_back(2*val);
                }
            }
        }
        int val=0;
                    while(st.size())
                    {
                        val+=st.back();
                        st.pop_back();
                    }
        return val;
    }
};