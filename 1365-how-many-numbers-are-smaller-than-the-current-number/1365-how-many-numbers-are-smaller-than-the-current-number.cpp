class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int n=nums.size(); 
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        for(auto &it:nums)
        {
            auto index=lower_bound(temp.begin(),temp.end(),it)-temp.begin();
            it=index;
        }
        return nums;
    }
};