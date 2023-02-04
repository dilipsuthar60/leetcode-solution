class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int>v;
        for(auto value:nums)
        {
            string s=to_string(value);
            for(auto ch:s)
            {
                int vt=ch-'0';
                v.push_back(vt);
            }
        }
        return v;
    }
};