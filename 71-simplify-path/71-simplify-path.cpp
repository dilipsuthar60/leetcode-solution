class Solution {
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string ans;
        vector<string>st;
        while(getline(ss,ans,'/'))
        {
           if(ans.size()==0||ans==".")
            {
                continue;
            }
            if(st.size()&&ans=="..")
            {
                st.pop_back();
            }
            else if(ans!="..")
            {
                st.push_back(ans);
            }
        }
        string result;
        if(st.size()==0)
        {
            return "/";
        }
        for(auto &it:st)
        {
            result+="/"+it;
        }
        return result; 
    }
};