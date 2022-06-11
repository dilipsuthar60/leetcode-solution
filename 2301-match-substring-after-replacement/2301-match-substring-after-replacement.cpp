class Solution {
public:
    int mp[260][260];
    bool find(string &s,string &p)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=p[i])
            {
                if(mp[p[i]][s[i]]==0)
                {
                    return false;
                }
            }
        }
        return true;
    }
   
bool matchReplacement(string s, string sub, vector<vector<char>>& mapp)
    {    
        int len=sub.size();
        int n=s.size();
        memset(mp,0,sizeof(mp));
        for(auto &it:mapp)
        {
            mp[it[0]][it[1]]++;
        }
        for(int i=0;i+len<=n;i++)
        {
            string new_string=s.substr(i,len);
            if(find(new_string,sub))
            {
                return true;
            }
        }
        return false;
    }
};