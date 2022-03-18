class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>occ(26,0);
        for(int i=0;i<n;i++)
        {
            occ[s[i]-97]++;
        }
        vector<bool>visited(n,false);
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            occ[s[i]-97]--;
            if(visited[s[i]-97])
            {
                continue;
            }
            while(st.size()&&st.top()>s[i]&&occ[st.top()-97])
            {
                visited[st.top()-97]=false;
                st.pop();
            }
            visited[s[i]-97]=true;
            st.push(s[i]);
        }
        string result(st.size(),'1');
        int index=st.size()-1;
        while(st.size())
        {
            result[index--]=st.top();
            st.pop();
        }
        return result;
    }
};