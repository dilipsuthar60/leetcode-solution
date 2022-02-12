class Solution {
public:
    int ladderLength(string start, string end, vector<string>& word)
    {
        int level=1;
        queue<string>q;
        q.push(start);
        unordered_set<string>st(word.begin(),word.end());
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                if(temp==end)
                {
                    return level;
                }
                st.erase(temp);
                for(int k=0;k<temp.size();k++)
                {
                    char ch=temp[k];
                    for(int i=0;i<26;i++)
                    {
                        temp[k]=i+'a';
                        if(st.count(temp)&&temp[k]!=ch)
                        {
                            q.push(temp);
                        }
                    }
                    temp[k]=ch;
                }
            }
            level++;
        }
        return 0;
    }
};