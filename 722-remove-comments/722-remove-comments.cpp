class Solution {
public:
    vector<string> removeComments(vector<string>& nums)
    {
        vector<string>ans;
        int comment=0;
        string take="";
        for(auto &v:nums)
        {
            int n=v.size();
            for(int i=0;i<n;i++)
            {
                if(!comment&&i+1<n&&v[i]=='/'&&v[i+1]=='/')
                {
                    break;
                }
                else if(!comment&&i+1<n&&v[i]=='/'&&v[i+1]=='*')
                {
                    comment=1;
                    i++;
                }
                else if(comment&&i+1<n&&v[i]=='*'&&v[i+1]=='/')
                {
                    comment=0;
                    i++;
                }
                else if(comment==0)
                {
                    take.push_back(v[i]);
                }
            }
            if(comment==0&&take.size())
            {
                ans.push_back(take);
                take.clear();
            }
        }
        return ans;
    }
};