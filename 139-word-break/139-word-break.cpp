class Solution {
public:
    bool wordBreak(string s, vector<string>& word) 
    {
        unordered_set<string>st(word.begin(),word.end());
        queue<int>q;
        q.push(0);
        int n=s.size();
        int vis[301];
        memset(vis,0,sizeof(vis));
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            if(temp==n)
            {
                return true;
            }
            if(vis[temp])
            {
                continue;
            }
            vis[temp]=1;
            string str="";
            for(int i=temp;i<n;i++)
            {
                str.push_back(s[i]);
                if(st.find(str)!=st.end())
                {
                    q.push(i+1);
                }
            }
        }
        return false;
    }
};