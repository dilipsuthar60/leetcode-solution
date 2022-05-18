class Solution {
public:
    void find(string &s,int index,vector<string>&v)
    {
            v.push_back(s);
        
        for(int i=index;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                s[i]^=32;
                find(s,i+1,v);
                s[i]^=32;
            }
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        vector<string>v;
        find(s,0,v);
        return v;
    }
};