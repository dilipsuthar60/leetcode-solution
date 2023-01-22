class Solution {
public:
    bool valid(string s)
    {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
    void find(string &s,int index,vector<string>curr,vector<vector<string>>&ans)
    {
        if(index>=s.size())
        {
            ans.push_back(curr);
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            if(valid(s.substr(index,i-index+1)))
            {
                curr.push_back(s.substr(index,i-index+1));
                find(s,i+1,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        find(s,0,curr,ans);
        return ans;
    }
};