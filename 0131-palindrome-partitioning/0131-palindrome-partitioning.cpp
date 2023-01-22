class Solution {
public:
    bool pal(string s)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }
    void find(string s,int index,vector<string>&res,vector<vector<string>>&ans)
    {
        if(index==s.size())
        {
            ans.push_back(res);
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            if(pal(s.substr(index,i-index+1)))
            {
                res.push_back(s.substr(index,i-index+1));
                find(s,i+1,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string>res;
        vector<vector<string>>ans;
        find(s,0,res,ans);
        return ans;
    }
};