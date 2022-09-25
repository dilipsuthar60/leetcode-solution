class Solution {
public:
    vector<string> sortPeople(vector<string>&nums, vector<int>&h)
    {
        int n=nums.size();
        vector<pair<int,string>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({h[i],nums[i]});
        }
        int i=0;
        sort(v.rbegin(),v.rend());
        for(auto &t:v)
        {
            nums[i++]=t.second;
        }
        return nums;
    }
};