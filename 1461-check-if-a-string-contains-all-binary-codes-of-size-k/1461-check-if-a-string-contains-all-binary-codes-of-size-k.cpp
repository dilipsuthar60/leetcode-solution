class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        deque<char>dq;
        unordered_set<string>st;
        for(int i=0;i<s.size();i++)
        {
            dq.push_back(s[i]);
            if(dq.size()==k)
            {
                st.insert({dq.begin(),dq.end()});
                dq.pop_front();
            }
        }
        return st.size()==(1<<k);
    }
};