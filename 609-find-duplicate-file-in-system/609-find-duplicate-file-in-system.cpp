class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& nums) {
        unordered_map<string,vector<string>>mp;
        for(auto &s:nums)
        {
            stringstream ss(s);
            string root;
            getline(ss,root,' ');
            string curr="";
            while(getline(ss,curr,' '))
            {
                string file_name=root+'/'+curr.substr(0,curr.find('('));
                string content=curr.substr(curr.find('(')+1,curr.find(')')-curr.find('(')-1);
                mp[content].push_back(file_name);
            }
        }
        vector<vector<string>>ans;
        for(auto &[content,file_name]:mp)
        {
            if(file_name.size()>1)
            {
                ans.push_back(file_name);
            }
        }
        return ans;
    }
};