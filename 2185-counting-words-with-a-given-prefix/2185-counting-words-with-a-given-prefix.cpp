class Solution {
public:
    int prefixCount(vector<string>& nums, string pref) 
    {
        int count=0;
        for(auto s:nums)
        {
            string new_string="";
            for(int i=0;i<pref.size()&&i<s.size();i++)
            {
                new_string.push_back(s[i]);
            }
            if(new_string==pref)
            {
                count++;
            }
        }
        return count;
    }
};