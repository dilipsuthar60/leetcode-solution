class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string>&nums, string s)
    {
        int n=s.size();
        sort(nums.begin(),nums.end());
        vector<vector<string>>ans;
        string now="";
        for(int i=0;i<n;i++)
        {
            now.push_back(s[i]);
            int index=lower_bound(nums.begin(),nums.end(),now)-nums.begin();
            vector<string>res;
            for(int j=index;j<min(index+3,(int)nums.size())&&nums[j].substr(0,now.size())==now;j++)
            {
                res.push_back(nums[j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};