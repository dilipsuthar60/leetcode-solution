class Solution {
public:
    int minSwaps(string s) 
    {
        int n=s.size();
        stack<char>st;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size())
                {
                    st.pop();
                }
                else
                {
                    count++;
                }
            }
        }
        return (count+1)/2;
    }
};