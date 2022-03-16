class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n=pushed.size();
        stack<int>s;
        int j=0;
        for(int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            while(s.size()&&popped[j]==s.top())
            {
                j++;
                s.pop();
            }
        }
        return s.size()==0;
    }
};