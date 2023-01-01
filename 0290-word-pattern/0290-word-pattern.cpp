class Solution {
public:
    bool wordPattern(string p, string s) 
    {
        vector<string>v;
        istringstream ss(s);
        string ans;
        while(ss>>ans)
        {
            v.push_back(ans);
            // cout<<ans<<endl;
        }
        if(v.size()!=p.size()) return false;
        unordered_map<string,char>mp1;
        unordered_map<char,string>mp2;
        for(int i=0;i<v.size();i++)
        {
            if(mp1.find(v[i])!=mp1.end())
            {
                if(mp1[v[i]]!=p[i])
                {
                    return false;
                }
            }
            if(mp2.find(p[i])!=mp2.end())
            {
                if(mp2[p[i]]!=v[i])
                {
                    return false;
                }
            }
            mp1[v[i]]=p[i];
            mp2[p[i]]=v[i];
        }
        return true;
    }
};