class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>&nums, int extra)
    {
        vector<bool>v;
        int max_val=*max_element(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i<n;i++)
        {
            v.push_back((nums[i]+extra>=max_val));
        }
        return v;
    }
};