class Solution {
public:
    map<pair<char,char>,int>mp;
    bool find(string &s,string &p)
    {
        if(s.size()!=p.size())
        {
            return false;
        }
        
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=p[i])
            {
                if(mp.find({p[i],s[i]})==mp.end())
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
        for(auto &it:mapp)
        {
            mp[{it[0],it[1]}]++;
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