class Solution {
public:
    int minimumLength(string s) 
    {
        deque<char>dq;
        for(auto &it:s)
        {
            dq.push_back(it);
        }
        while(dq.size()>1&&dq.front()==dq.back())
        {
            char ch=dq.front();
            while(dq.size()&&ch==dq.front())
            {
                dq.pop_front();
            }
            while(dq.size()&&ch==dq.back())
            {
                dq.pop_back();
            }
        }
        return  dq.size();
    }
};