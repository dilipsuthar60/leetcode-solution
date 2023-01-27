class Solution {
public:
    unordered_set<string>st;
    bool find(string s)
    {
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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),[&](auto &a,auto &b){return a.size()<b.size();});
        vector<string>ans;
        for(auto it:words)
        {
            if(find(it))
            {
                ans.push_back(it);
            }
            else
            {
                st.insert(it);
            }
        }
        return ans;
    }
};