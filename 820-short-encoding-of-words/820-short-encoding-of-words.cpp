class Solution {
public:
    int minimumLengthEncoding(vector<string>&nums)
    {
        unordered_set<string>s(nums.begin(),nums.end());
        for(auto it:nums)
        {
            int n=it.size();
            for(int i=1;i<n;i++)
            {
                s.erase(it.substr(i));
            }
        }
        int count=0;
        for(auto it:s)
        {
            count+=it.size()+1;
        }
        return count;
    }
};