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
              v.push_back(stoi(string(1,ch)));
            }
        }
        return v;
    }
};