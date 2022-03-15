class Solution {
public:
    
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) 
    {
        int count=0;
        vector<pair<int,pair<int,int>>>v;
        auto value=[&](string s)
        {
            int val=0;
            for(int i=0;i<s.size();i++)
            {
                val=val*10+(s[i]-'0');
            }
            return val;
        };
        for(auto it:nums)
        {
            string curr="";
            string s=to_string(it);
            for(int i=0;i<s.size();i++)
            {
                curr+=to_string(map[s[i]-'0']);
            }
            v.push_back({value(curr),{count++,it}});
        }
        sort(v.begin(),v.end(),[&](auto &a,auto &b)
             {
                   return a.first==b.first?a.second.first<b.second.first:a.first<b.first;
             });
        vector<int>a;
        for(auto it:v)
        {
            a.push_back(it.second.second);
        }
        return a;
    }
};