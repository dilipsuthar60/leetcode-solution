class Solution {
public:
    class node
    {
        public:
        char ch;
        int f;
        node(char ch,int f)
        {
            this->ch=ch;
            this->f=f;
        }
    };
    string removeDuplicates(string s, int k) 
    {
        int n=s.size();
        stack<node>st;
        node first('#',1);
        st.push(first);
        for(int i=n-1;~i;i--)
        {
            if(st.top().ch!=s[i])
            {
                st.push(node(s[i],1));
            }
            else if(++st.top().f==k)
            {
                st.pop();
            }
        }
        string ans="";
        while(st.size())
        {
            int freq=st.top().f;
            char chat=st.top().ch;
            ans+=string(freq,chat);
            st.pop();
        }
        ans.pop_back();
        // ans.erase(ans.begin());
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};